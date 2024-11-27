mkdir -p build
cd build/

VER=$(git describe --abbrev=4 --tags --dirty --match "v*")

echo "#ifndef TEST_VERSION_H_" > version.h
echo "#define TEST_VERSION_H_" >> version.h
echo "#define BUILD_SYSTEMS_VERSION \"$VER\""  >> version.h
echo "#endif  /* TEST_VERSION_H_ */" >> version.h

gcc -c ../LibLog/log.c -I ../LibLog/ -o ./LibLog.o
ar rcs libLog.a LibLog.o

g++ -o main ../main.cpp -L ./ -l Log -I ../LibLog/  -I ./

./main 
