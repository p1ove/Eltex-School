CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
SRCDIR=src/lib_src
SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:$(SRCDIR)/%.c=$(SRCDIR)/%.o)

all: clean book.so ex

ex: $(OBJ) src/main.c
	$(CC) $(STDFLAGS) src/main.c -L$(PWD) -lbook -o book

book.so: $(OBJ)
	$(CC) -shared -o $@ $^

clean:
	rm -rf $(SRCDIR)/*.o *.so book
