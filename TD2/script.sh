if [ -d "./build" ];then 
   rm -r -d build
fi
mkdir build
cd build
#cmake ..
#Avec alien
cmake .. -DCMAKE_PREFIX_PATH=/usr/local/lib
#En mode Release
#cmake .. -DCMAKE_BUILD_TYPE=Release
make
ctest
./Main.exe
./Test.exe

