rem don't forget to compile gen.cpp, sol.cpp and brute.cpp
rem run this file as `test`
@echo off

rem `gen` is the binary file created after compiling `gen.cpp`
rem `in` file contains the generated testcase
gen >in

rem `sol` is the binary file created after compiling `sol.cpp`
rem `out` file contains your output
sol <in >out

rem `brute` is the binary file created after compiling `brute.cpp`
rem `ok` file contains the expected output
brute <in >ok

rem compare `out` file and `ok` file
fc out ok
if errorlevel 1 exit
test