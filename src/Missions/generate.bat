@echo off

if %1 == "" goto error

echo Compiling %1%
cd %1%
for %%i in (*.kas) do @..\compile_kas %%i

cd ..

goto done:

:error
echo No folder specified
:done


