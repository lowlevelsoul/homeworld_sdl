@echo off
setLocal EnableDelayedExpansion
if [%1]==[] goto noinput

set CPP=..\..\..\..\..\tools\mcpp-2.7.2\bin\mcpp
set KAS2C=..\..\..\bin\windows\kas2c

set SRC_FILE=%1%

rem Preprocess the file
set PREPROCESS_NAME=%SRC_FILE:kas=kpp%
%CPP% -P -D _WIN32 %SRC_FILE% %PREPROCESS_NAME%

rem Now generate the c files
set C_FILENAME_BARE=%SRC_FILE:.kas=%
set OUT_MISSION_C=../Generated/%C_FILENAME_BARE%.c
set OUT_MISSION_H=../Generated/%C_FILENAME_BARE%.h
set OUT_MISSION_FUNC=../Generated/%C_FILENAME_BARE%.func.c
rem echo %OUT_MISSION_C%
rem echo %OUT_MISSION_H%
rem echo %OUT_MISSION_FUNC%

%KAS2C% %PREPROCESS_NAME%  %OUT_MISSION_C% %OUT_MISSION_H% %OUT_MISSION_FUNC%

rem Cleanup the preprocessed file
del %PREPROCESS_NAME%    

goto done
:noinput
@echo No input parameter
:done