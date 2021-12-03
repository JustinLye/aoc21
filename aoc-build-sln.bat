@echo off
setlocal enableextensions

set config_type=Release
if not "%1" == "" set config_type=%1

call set_vs_env
msbuild build-files\aoc.sln -t:Build -p:Configuration=%config_type%