CC = g++

main:$(OBJ)
	$(CC) -c basicFunctions.cpp
	$(CC) -c main.cpp
	$(CC) -o main.out basicFunctions.o main.o

