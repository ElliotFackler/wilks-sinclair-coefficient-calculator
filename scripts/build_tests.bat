@echo off
REM Build test executable
cl.exe /EHsc /nologo /Fe:tests.exe tests.cpp utils.cpp

REM Run tests
if %ERRORLEVEL% EQU 0 (
    echo.
    echo Running tests...
    .\tests.exe
    if %ERRORLEVEL% EQU 0 (
        echo Tests passed!
    ) else (
        echo Some tests failed!
    )
) else (
    echo Compilation failed!
    exit /b 1
)
