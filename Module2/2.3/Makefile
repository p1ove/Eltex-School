CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
SRC=$(wildcard src/*.c)
OBJ=$(patsubst %src/.c,%src/.o, ${SRC})

all: clean obj ex

obj:
	$(CC) -c $(STDFLAGS) $(SRC)

ex:
	$(CC) $(STDFLAGS) $(OBJ) -o calc
	rm -rf *.o

clean:
	rm -rf *.o calc