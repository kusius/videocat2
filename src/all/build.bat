@echo off
set PROJECT_DIR=%cd%
set COMMON_DIR=%PROJECT_DIR%\..\common
set SRCDIR=%PROJECT_DIR%
set PROJECT_BUILD_DIR=%PROJECT_DIR%\build
set DLL_DIR=%COMMON_DIR%\thirdparty\bin

set PROJECT_LIB_DIRECTORIES=%COMMON_DIR%\thirdparty\lib

:: MSVC reads these env variables by default to search for objects, 
:: libraries and include directories
set LIB=%LIB%;%PROJECT_LIB_DIRECTORIES%
set INCLUDE=%INCLUDE%;^
%SRCDIR%;^
%COMMON_DIR%;^
%COMMON_DIR%\thirdparty\libmisb\include;^
%COMMON_DIR%\thirdparty\gsl;^
%COMMON_DIR%\thirdparty\klvp;^
%COMMON_DIR%\thirdparty\loki;^
%COMMON_DIR%\thirdparty\tinycthread;^
%COMMON_DIR%\thirdparty\nanogui;^
%COMMON_DIR%\thirdparty\argh;^
%COMMON_DIR%\thirdparty\ffmpeg;


@REM Debug configuration
set DEBUG_COMPILER_FLAGS=/nologo /Zi /EHsc /DWINDOWS /D_DEBUG /MDd

set SOURCE_FILES=%COMMON_DIR%\thirdparty\tinycthread\*.c^
 %COMMON_DIR%\*.cpp^
 %SRCDIR%\main.cpp

set DEBUG_LINK_LIBRARIES=avformat.lib avcodec.lib avutil.lib klvpd.lib ldsdbd.lib ole32.lib user32.lib Ws2_32.lib

 
:: We use pushd popd to make sure 
:: all the compilation output goes into build
mkdir %PROJECT_BUILD_DIR%
pushd %PROJECT_BUILD_DIR%

cl /std:c++20 %DEBUG_COMPILER_FLAGS% %SOURCE_FILES% %DEBUG_LINK_LIBRARIES% /Fe:videocat.exe

popd

@rem TODO: clean up unused dlls and libs from the dll dir.
xcopy /d %DLL_DIR%\* %PROJECT_BUILD_DIR%