@echo off
setlocal enableextensions

if not exist build-files mkdir build-files
cd build-files

cmake ..\