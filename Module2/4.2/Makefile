CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
SRC=$(wildcard src/queue*.c)
TEST_SRC=$(wildcard src/check*.c)
OBJ=queue.o
CHECK_FLAGS= -lcheck -lsubunit -lrt -lpthread -lm

all: clean test

obj:
	$(CC) -c $(STDFLAGS) $(SRC)

test:clean queue.a
	${CC} $(STDFLAGS) ${TEST_SRC} queue.a -o test $(CHECK_FLAGS) -g
	rm -rf *.o *.a
	./test

simple_test:clean queue.a
	${CC} $(STDFLAGS) src/simple_test.c queue.a -o test -g
	rm -rf *.o *.a
	./test

queue.a: ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ queue.o
	ranlib $@

clean:
	rm -rf *.o *.a test