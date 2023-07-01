CC = gcc
CFLAGS = -g -Wall -O3 -std=c11
CFLAGS += 
LDFLAGS = -lm
LDFLAGS += -lSDL2

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = bin

.PHONY: all clean

all: dirs libs build

libs:

dirs:
	mkdir -p $(BIN)

build: $(OBJ)
	$(CC) -o $(BIN)/main $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)

run: all
	./$(BIN)/main