# don't forget to compile gen.cpp, sol.cpp and brute.cpp
# run this file as `bash test.sh`

for((i = 1; ; i++)); do
    echo $i
    # gen.out is the binary file created after compiling gen.cpp
    # `in` file contains the generated testcase
    ./gen.out > in
    
    # sol.out is the binary file created after compiling sol.cpp
    # `out` file contains your output
    ./sol.out < in > out
    
    # brute.out is the binary file created after compiling brute.cpp
    # `ok` file contains the expected output
    ./brute.out < in > ok
    diff -w out ok || break
done