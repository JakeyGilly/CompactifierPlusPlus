ifeq ($(OS),Windows_NT)
    TARGET = Compactifier.exe
else
    TARGET = Compactifier.out
endif

SOURCE	= src/main.cpp src/fileio.cpp src/formatting/global.cpp src/formatting/languages/python/formatter.cpp
HEADER	= headers/fileio.hpp headers/formatting.hpp
CC	 	= g++
FLAGS	= -Wall -std=c++20

all: $(OBJS)
	$(CC) ${SOURCE} -o $(TARGET) ${FLAGS}

clean:
	rm -f $(TARGET)
