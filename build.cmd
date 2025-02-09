@echo off

set COMPILER=C:/mingw64/bin/g++.exe

set INCLUDE_PATH=%~dp0/include
set LIB_PATH=%~dp0/lib
set SRC_DIR=%~dp0src

set OUTPUT_DIR=%~dp0

:: Compiler flags
set CXXFLAGS=-g -std=c++20 -I"%INCLUDE_PATH%"

:: Libraries to link
set LIBS=-L"%LIB_PATH%" -ltag -lzlib

:: Build the project
echo Building the project...
"%COMPILER%" %CXXFLAGS% "%SRC_DIR%/*.cpp" -o "%OUTPUT_DIR/AlbumRename.exe%" %LIBS%

if %ERRORLEVEL% neq 0 (
    echo Build failed!
) else (
    echo Build successful!
)
