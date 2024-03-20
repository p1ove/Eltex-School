CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, ${SRC})

all: obj ex

obj:
	$(CC) -c $(STDFLAGS) $(SRC)

ex:
	$(CC) $(STDFLAGS) $(OBJ) -o book
	rm -rf *.o

clean:
	rm -rf *.o book