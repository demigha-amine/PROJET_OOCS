cd build
rm CMakeCache.txt
cmake ..
make
ctest
./Main.exe
./Test.exe

