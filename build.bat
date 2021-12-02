@echo off
setlocal enableextensions

if not exist build-files mkdir build-files
cd build-files

cmake ..\
call set_vs_env
msbuild aoc.sln -t:Build -p:Configuration=Release