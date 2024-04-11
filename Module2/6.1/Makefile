CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
SRC=$(wildcard src/lib_src/*.c)
OBJ=$(patsubst %src/lib_src/.c,%src/lib_src/.o, ${SRC})

all: clean libbook.a obj ex
	rm -rf *.o

obj:
	$(CC) -c $(STDFLAGS) src/main.c

ex:
	$(CC) $(STDFLAGS) main.o -L. -lbook -o book

libbook.a: ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ *.o
	rm -rf *.o
	ranlib $@

clean:
	rm -rf *.o *.a book