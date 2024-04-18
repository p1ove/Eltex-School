CC=gcc
STDFLAGS= 
SRC=$(wildcard src/lib_src/*.c)
OBJ=$(patsubst %src/lib_src/.c,%src/lib_src/.o, ${SRC})

all: clean libbook.a obj ex
	rm -rf *.o

obj:
	$(CC) -c $(STDFLAGS) src/main.c
	$(CC) -c $(STDFLAGS) src/write.c

ex:
	$(CC) $(STDFLAGS) main.o write.o -L. -lbook -o book

libbook.a: ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ *.o
	rm -rf *.o
	ranlib $@

clean:
	rm -rf *.o *.a book