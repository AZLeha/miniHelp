# Устанавливаем переменную, которая будет использоваться для сборки версии библиотеки LibTest
LIB_VERSION := v0.1
VERSION ?= $(shell git describe --abbrev=4 --tags --dirty --match "v*")
LIB_SRC:=./LibTest/log.c 
LIB_INC:=./LibTest/
LIB_OBJ:=$(LIB_SRC:.c=.o)

# Цели для сборки различных частей проекта

# Цель для сборки основного кода LibTest

# Все цели вместе
all: libLog version
	g++ -o main.exe main.cpp -L ./build -l Log -I $(LIB_INC) -I ./build


libLog: $(LIB_OBJ)
	ar rcs ./build/libLog.a ./build/$(LIB_OBJ)

.c.o: 
	mkdir -p build/LibTest
	gcc -c $< -o ./build/$@ -I $(LIB_INC)

version: 
	mkdir -p build
	echo "#ifndef TEST_VERSION_H_" > ./build/version.h
	echo "#define TEST_VERSION_H_" >> ./build/version.h
	echo "#define BUILD_SYSTEMS_VERSION \"$(VERSION)\""  >> ./build/version.h
	echo "#endif  /* TEST_VERSION_H_ */" >> ./build/version.h

clean:
	rm -r ./build
	rm main.exe

run:
	./main.exe