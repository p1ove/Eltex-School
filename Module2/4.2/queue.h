#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct Item{
    int val;
    int priority;
struct Item* next;
struct Item* prev;
};

#endif //QUEUE_H