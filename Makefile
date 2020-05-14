all: function.o main.o laba

function.o: function.cpp
	g++ -c -o function.o function.cpp

main.o: main.cpp
	g++ -c -o main.o main.cpp

laba: function.o main.o
	g++ main.o function.o -o laba