#Makefile

all: add-nbo

add-nbo.o: add-nbo.cpp
	gcc -c -o add-nbo.o add-nbo.cpp

add-nbo: add-nbo.o
	gcc -o add-nbo add-nbo.o

clean: 
	rm -f add-nbo.o
	rm -f add-nbo
