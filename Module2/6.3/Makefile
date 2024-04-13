CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
SRC=$(wildcard src/*.c)
OBJ=$(patsubst %src/.c,%src/.o, ${SRC})

all: clean libcalc.so obj ex
	rm -rf *.o

obj:
	$(CC) -c $(STDFLAGS) $(SRC)

ex:
	$(CC) $(STDFLAGS) $(OBJ) -L. -ldev -L. -lmult -L. -lsub -L. -lsum -o calc

libcalc.so:
	$(CC) -shared $(STDFLAGS) src/lib_src/dev.c -o libdev.so
	$(CC) -shared $(STDFLAGS) src/lib_src/mult.c -o libmult.so
	$(CC) -shared $(STDFLAGS) src/lib_src/summ.c -o libsum.so
	$(CC) -shared $(STDFLAGS) src/lib_src/sub.c -o libsub.so

clean:
	rm -rf *.o *.so calc