all: main

CFLAGS=-I/home/bill/ws/porting/target/jdk/jdk1.7.0_60_sflt/include/ -Wall
CPP=arm-marvell-linux-gnueabi-g++
LDFLAGS=-lsdtapi -ltermb -lwlt -lwltwr -Llib

main: main.cpp
	${CPP} main.cpp $(LDFLAGS) $(CFLAGS) -o main 

clean:
	rm main
