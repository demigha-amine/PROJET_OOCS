cd build
rm CMakeCache.txt
cmake ..
#Avec Alien
#cmake .. -DCMAKE_PREFIX_PATH=/usr/local/lib
make
ctest
./Main.exe
./Test.exe

