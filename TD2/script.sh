if [ -d "./build" ];then 
   rm -r -d build
fi
mkdir build
cd build
cmake ..
make
ctest
./Main.exe
./Test.exe

