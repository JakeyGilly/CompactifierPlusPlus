ifeq ($(OS),Windows_NT)
    TARGET = Compactifier.exe
else
    TARGET = Compactifier.out
endif

SOURCE	= src/main.cpp src/fileio.cpp src/config.cpp src/formatting/lexer.cpp src/formatting/tokeniser.cpp
HEADER	= headers/fileio.hpp headers/formatting.hpp headers/config.hpp headers/tokeniser.hpp
CC	 	= g++
FLAGS	= -Wall -std=c++17 -g

all: $(OBJS)
	$(CC) ${SOURCE} -o $(TARGET) ${FLAGS}

clean:
	rm -rf $(TARGET) output.py Compactifier.out.dSYM/ output.c output.cpp
