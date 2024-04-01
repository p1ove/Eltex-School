#ifndef LIST_2_H
#define LIST_2_H

#include <stdio.h>
#include <stdlib.h>

struct Item{
int value;
struct Item* next;
struct Item* prev;
};

#endif //LIST_2_H