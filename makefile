ifeq ($(OS),Windows_NT)
    TARGET = Compactifier.exe
else
    TARGET = Compactifier.out
endif

OBJS	= main.o fileio.o formatting/global.o formatting/languages/python/formatter.o
SOURCE	= main.cpp fileio.cpp formatting/global.cpp formatting/languages/python/formatter.cpp
HEADER	= headers/fileio.hpp headers/formatting.hpp
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(TARGET) $(LFLAGS)
	rm -f $(OBJS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++17

fileio.o: fileio.cpp
	$(CC) $(FLAGS) fileio.cpp -std=c++17

global.o: formatting/global.cpp
	$(CC) $(FLAGS) formatting/global.cpp -std=c++17

formatterpy.o: formatting/languages/python/formatter.cpp
	$(CC) $(FLAGS) formatting/languages/python/formatter.cpp -std=c++17

clean:
	rm -f $(OBJS) $(TARGET)
