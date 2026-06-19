// ExtractBig.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdint.h>
#include <vector>


class CMemStream {
public:
	CMemStream() {
	}

	~CMemStream() {
	}

    bool Load( const char * filename ) {
		FILE * fp = fopen( filename, "rb" ); 
        if ( fp == NULL ) {
            return false;
        }

		fseek( fp, 0, SEEK_END );
		size_t fileSize = ftell( fp );
		fseek( fp, 0, SEEK_SET );
		buffer.resize( fileSize );

		size_t bytesRead = fread( buffer.data(), 1, fileSize, fp );
		fclose( fp );
		return bytesRead == fileSize;
    }

	template <typename T>
	size_t Read( T * dest, size_t count ) {
		size_t numBytesToRead = ReadRaw( dest, sizeof( T ) * count ) / sizeof( T );
		return numBytesToRead;
	}

	bool Seek( int64_t offset, int origin ) {

		int64_t newPtr = 0;
		switch ( origin ) {
		case SEEK_SET:
			newPtr = offset;
			break;
		case SEEK_CUR:
			newPtr = bufferPtr + offset;
			break;
		case SEEK_END:
			newPtr = buffer.size() + offset;
			break;
		default:
			return false;
		}

		if ( newPtr < 0 || newPtr > buffer.size() ) {
			return false;
		}

		bufferPtr = newPtr;
		return true;
	}

	std::vector<uint8_t> & GetBuffer() {
		return buffer;
	}

protected:

    size_t ReadRaw( void * dest, size_t size ) {
        if ( bufferPtr + size > buffer.size() ) {
            return 0;
        }

        size_t amtRem = buffer.size() - bufferPtr;
		size_t amtToRead = ( amtRem < size ) ? amtRem : size;

		memcpy( dest, &buffer[ bufferPtr ],  amtToRead );
		bufferPtr += amtToRead;

		return size;
    }

protected:
	std::vector<uint8_t>    buffer;
	uint64_t                bufferPtr = 0;

};

class CBigTocEntry {
public:
	typedef std::vector<CBigTocEntry> Vector_t;

    CBigTocEntry() {
    }

    ~CBigTocEntry() {
	}

    bool Read( CMemStream & str ) {
		uint16_t pad1;
		uint8_t pad2[ 3 ];
		str.Read( &nameCRC1, 1 );	
		str.Read( &nameCRC2, 1 );
		str.Read( &nameLength, 1 );
		str.Read( &pad1, 1 );	
		str.Read( &storedLength, 1 );
		str.Read( &realLength, 1 );
		str.Read( &offset, 1 );
		str.Read( &timeStamp, 1 );
		str.Read( &compressionType, 1 );
		str.Read( pad2, 3 );

		return true;
    }

public:
    // together, the CRCs and nameLength make up a very unique identifier for
    // the filename (so we don't have to do string compares when searching or
    // or store long names in the TOC)
    uint32_t    nameCRC1; 
    uint32_t    nameCRC2;  // CRC of 1st and 2nd halves of name
    uint16_t    nameLength;

    //char name[BF_MAX_FILENAME_LENGTH];  for speed & space concerns, these now preceed the datafile portions of the bigfile

    uint32_t    storedLength;
    uint32_t    realLength;
    uint32_t    offset;
    uint32_t    timeStamp;
    uint8_t    compressionType;  // 0/1
};

class CBigToc {
public:
	CBigToc() {
	}

    ~CBigToc() {
    }

    bool Read( CMemStream & str ) {
		char header[ 16 ];
		memset( header, 0, sizeof( header ) );

		str.Read( header, 7 );	

		str.Read( &numFiles, 1 );
		str.Read( &flags, 1 );

		entries.resize( numFiles );

		for ( int i = 0; i < numFiles; i++ ) {	
			CBigTocEntry & entry = entries[ i ];

			bool entryOk = entry.Read(str);
			if ( entryOk == false ) {
				return false;
			}
		}

		return true;
	}

public:
    int32_t                     numFiles;
    int32_t                     flags;
    CBigTocEntry::Vector_t      entries;
};

class CBigEntryData {
public:
	typedef std::vector<CBigTocEntry> Vector_t;

	CBigEntryData() {
	}

	~CBigEntryData() {
	}

	void Read( CMemStream & str, const CBigTocEntry & entry ) {
		str.Seek( entry.offset, SEEK_SET );

		data.resize( entry.storedLength );
		str.Read( data.data(), entry.storedLength );
	}

	std::string				path;
	std::vector<uint8_t>    data;
};


class CBigFile {
public:
	CBigFile() {

	}

	~CBigFile() {

	}

	bool Load( const char * filename ) {
		bool loadOk = stream.Load( filename );
		if ( loadOk == false ) {
			return false;
		}

		bool tocReadOk = toc.Read( stream );
		if ( tocReadOk == false ) {
			return false;
		}

		LoadEntries();

		return true;
	}


	bool LoadEntries() {
		entries.resize( toc.entries.size() );

		for ( int i = 0; i < toc.numFiles; i++ ) {
			const CBigTocEntry & entry = toc.entries[ i ];
			const char * dataStart = ( const char *) stream.GetBuffer().data() + entry.offset;
			uint8_t * actualDataStart = ( uint8_t * )dataStart + entry.nameLength; // skip over the filename
		}

		return true;
	}

public:
	CBigToc                     toc;
	CMemStream					stream;
	CBigEntryData::Vector_t		entries;
};


int main() {
	CBigFile bigFile;
	bool loadOk = bigFile.Load( "D:\\Sierra\\Homeworld\\homeworld.big" );
	if ( loadOk == false ) {
		return -1;
	}

	return 0;
}