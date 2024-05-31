@echo on

REM Get the directory of the batch script
set "batch_dir=%~dp0"

REM Set the MSBuild path
set "MSBUILD_PATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\MSBuild\Current\Bin"

REM Building UnitTest1
"%MSBUILD_PATH%\MSBuild.exe" /p:PlatformTarget=x64 /p:Configuration=Debug "%batch_dir%UnitTest1.sln"

