CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

Main : Main.o cellType.o cellTable.o
	$(CC) $(LFLAGS) Main.o cellType.o cellTable.o -o Main

Main.o : Main.cpp cellType.h cellType.cpp cellTable.h cellType.cpp
	$(CC) $(CFLAGS) Main.cpp

cellType.o : cellType.h cellType.cpp
	$(CC) $(CFLAGS) cellType.cpp

cellType.o : cellTable.h cellTable.cpp
	$(CC) $(CFLAGS) cellTable.cpp

clean:
	\rm *.o Main

