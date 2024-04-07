#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item{
    char value[100];
    int priority;
struct Item* next;
struct Item* prev;
};

struct Item* InsertSort(char* value, int prior, struct Item* head);
struct Item* deleteValue(int priority, struct Item* head);
void deleteList(struct Item* head);
void printList(struct Item* head);

#endif //QUEUE_H