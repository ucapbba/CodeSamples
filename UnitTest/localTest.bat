@echo on

REM Get the directory of the batch script
set "batch_dir=%~dp0"

REM Set the MSBuild path
set "VSTEST_PATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\IDE\Extensions\TestPlatform"

REM Debug Testing Dll
"%VSTEST_PATH%\vstest.console.exe" "%batch_dir%/x64/Debug/UnitTest1.dll"

REM Capture the exit code
set "exit_code=%errorlevel%"

REM Check if tests failed
if %exit_code% neq 0 (
    echo Unit tests failed. Build will be stopped.
    exit /b %exit_code%
)

REM If tests passed, continue with the build
echo Unit tests passed. Proceeding with the build.

pause