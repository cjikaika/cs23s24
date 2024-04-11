TARGET = counting_program
MAIN = counting_main.cpp
SRC = counting_source.cpp
HEAD = counting_header.h
CC = g++
CFLAGS = -Wall -Wextra -pedantic
OM = counting_main.o
OS = counting_source.o
OBJ = $(OM) $(OS)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(OM): $(MAIN) $(HEAD)
	$(CC) $(CFLAGS) -c $(MAIN)

$(OS): $(SRC) $(HEAD)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ) $(TARGET)