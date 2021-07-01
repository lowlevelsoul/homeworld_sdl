@echo off
setLocal EnableDelayedExpansion
if [%1]==[] goto noinput

set CPP=..\..\..\..\..\tools\mcpp-2.7.2\bin\mcpp
set KAS2C=..\..\..\bin\windows\kas2c

set OUT_MISSION_C=""

rem Check to see if we caught an included kas file. If so, just exit
echo.%1 | findstr /C:"kash" 1>nul
if errorlevel 1 (
    call ../compile_kas2.bat %1%
) else (
    goto done
)

goto done
:noinput
@echo No input parameter
:done