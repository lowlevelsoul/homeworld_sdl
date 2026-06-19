#ifndef ___CLIENTCDKEY_H
#define ___CLIENTCDKEY_H

#if 0

// ClientCDKey

// Class that implements WON CD-Key functionality for use by clients.  Allows
// conversion to/from human readable string.  Implements persistence to the registry
// in a secure manner.  Implements a lightweight validation check of the key.

#include "tiPlatform.h"
#include <ostream>

// Forwards
namespace WONCrypt {
	class BFSymmetricKey;
};


// In WONCDKey namespace
namespace WONCDKey
{

class ClientCDKey
{
public:
	// Standard constructor
	// ProductName is string representing product using the CDKey, (i.e., "Homeworld")
	// *IMPORTANT*  product must be at least 3 chars for good security!!!
	TI_API explicit ClientCDKey(const std::string& theProductR);

	// Copy Constructor
	TI_API ClientCDKey(const ClientCDKey& theKeyR);

	// Destructor
	virtual ~ClientCDKey(void)

	// Operators
	ClientCDKey& operator=(const ClientCDKey& theKeyR);
	bool_t operator==(const ClientCDKey& theKeyR) const;
	bool_t operator!=(const ClientCDKey& theKeyR) const;

	// Product access.  Careful setting product.  Product is used to encrypt/decypt
	// the key to/from its binary form and for the Lightweight check.
	const std::string& GetProduct() const;
	TI_API void SetProduct(const std::string& theProductR);

	// Check two keys for equality
	virtual bool_t IsEqual(const ClientCDKey& theKeyR) const;

	// Check validity of a key, performs lightweight check if needed.
	virtual bool_t IsValid() const;

	// Is this a beta key?
	bool_t IsBeta() const;

	// Init from raw, unencrypted key.  A return of true DOES NOT imply key is valid!
	// (Call IsValid() to verify validity).
	TI_API virtual bool_t Init(const __int64& theKeyR);

	// Initialize from Human readable string (dashes are optional):
	//   CVCN-CVCN-CVCN-CVCN-NNNN
	// Returns true if init is successful, false if not.  A return of true DOES NOT
	// imply key is valid!  (Call IsValid() to verify validity).
	TI_API virtual bool_t Init(const std::string& theStrR);

	// Init from encrypted binary image (what is returned by AsBinary).  A return of
	// true DOES NOT imply key is valid!  (Call IsValid() to verify validity).
	TI_API virtual bool_t Init(const WONCommon::RawBuffer& theKeyR);

	// Fetch as raw, unencrypted (64bit) key
	__int64 AsRaw() const;

	// Fetch as human readable string.  Validates key if needed if validate is true.
	// If Keys fails to validate, returns "#######INVALID KEY######"
	const std::string& AsString(bool_t validate=true) const;

	// Fetch as encrypted binary image.  Valdates key if needed.  Returns empty
	// buffer if key is not valid.
	const WONCommon::RawBuffer& AsBinary() const;

	// Load/Save key in registry securely (key is encrypted in the registry)
	virtual bool_t Load(void)
	virtual bool_t Save() const;

	// Clean key from registry
	virtual bool_t CleanReg(void)

protected:
	// Types
	enum ValidityState { Unknown, Invalid, Valid };

	// Members
	std::string           mProduct;     // Product string
	unsigned char         mLightCheck;  // Lightweight checksum
	WONCommon::RawBuffer  mKey;         // Key value
	mutable ValidityState mValidity;    // Current key validity

	// Buffers for string and binary versions of key
	mutable std::string          mStrKey;  // CD-Key as string
	mutable WONCommon::RawBuffer mBinKey;  // CD-Key as encrypted binary

	// Perform the light validity check.  Returns light checksum
	unsigned char LightValidityCheck() const;

	// Build human readable string rep of CDKey.  Fills in mStrKey
	void BuildStringKey() const;

	// Extract LightCheck, and Key from a buffer
	TI_API void FieldsFromBuffer(const __int64& theBuf);

	// Build buffer from LightCheck and Key
	__int64 BufferFromFields() const;

	// Decypt mBin Key into buffer
	TI_API bool_t DecryptKey(__int64& theBufR);

	// Encrypt buffer into mBinKey
	bool_t EncryptKey(const __int64& theBufR) const;

private:
	// Methods
	void BuildCChar(const __int64& theBuf, unsigned int& theOffset) const;
	void BuildVChar(const __int64& theBuf, unsigned int& theOffset) const;
	void BuildNChar(const __int64& theBuf, unsigned int& theOffset) const;
	void CreateSymmetricKey(WONCrypt::BFSymmetricKey& theSymKeyR) const;

	// Class methods
	TI_API static void RemoveSkipChars(string& theStrR);
	TI_API static char ValFromBits(const __int64& aBuf, unsigned int theOffset, unsigned int theBits);
	TI_API static bool_t ProcessCChar(__int64& theBuf, unsigned int& theOffset, char theChar);
	TI_API static bool_t ProcessVChar(__int64& theBuf, unsigned int& theOffset, char theChar);
	TI_API static bool_t ProcessNChar(__int64& theBuf, unsigned int& theOffset, char theChar);
};


// Inlines
inline bool_t
ClientCDKey::operator==(const ClientCDKey& theKeyR) const
{ return IsEqual(theKeyR); }

inline bool_t
ClientCDKey::operator!=(const ClientCDKey& theKeyR) const
{ return (! IsEqual(theKeyR)); }

inline const std::string&
ClientCDKey::GetProduct() const
{ return mProduct; }

inline void
ClientCDKey::SetProduct(const std::string& theProductR)
{ mProduct = theProductR; }

inline __int64
ClientCDKey::AsRaw() const
{ return BufferFromFields(void) }

};  //namespace WONCDKey


// Output operators
inline std::ostream&
operator<<(std::ostream& os, const WONCDKey::ClientCDKey& theKeyR)
{ os << theKeyR.AsString(void)  return os; }

#endif
#endif
