#include "main.h"

void add(struct contact *book, int *pid) {
    book = InsertValue(*pid+1, book);
  *pid += 1;
}