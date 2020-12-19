@echo off
cd /d %~dp0
if not exist build mkdir build
cd build
cmake .. -G"Visual Studio 16 2019"
::cmake .. -G"Visual Studio 16 2019" -A Win32
::cmake .. -G"Visual Studio 15 2017"
::cmake .. -G"Visual Studio 14 2015"
