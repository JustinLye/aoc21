@echo off
setlocal enableextensions

set config_type=Release
if not "%1" == "" set config_type=%1

call generate-build-files.bat
call aoc-build-sln.bat %config_type%