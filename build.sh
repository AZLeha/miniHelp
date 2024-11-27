mkdir build 
cd build/

VER=$(git describe --abbrev=4 --tags --dirty --match "v*")

echo "#ifndef TEST_VERSION_H_" > version.h
echo "#define TEST_VERSION_H_" >> version.h
echo "#define BUILD_SYSTEMS_VERSION \"$VER\""  >> version.h
echo "#endif  /* TEST_VERSION_H_ */" >> version.h

gcc -c ../LibTest/log.c -I ../LibTest/ -o ./LibTest.o  
ar rcs libLog.a LibTest.o  

g++ -o main ../main.cpp -L ./ -l Log -I ../LibTest/  -I ./

./main 
