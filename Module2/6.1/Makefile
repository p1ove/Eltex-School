CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
SRC=$(wildcard src/lib_src/*.c)
OBJ=$(patsubst %src/lib_src/.c,%src/lib_src/.o, ${SRC})

all: clean book.a obj ex
	rm -rf *.o

obj:
	$(CC) -c $(STDFLAGS) src/main.c

ex:
	$(CC) $(STDFLAGS) main.o book.a -o book

book.a: ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ *.o
	rm -rf *.o
	ranlib $@

clean:
	rm -rf *.o *.a book