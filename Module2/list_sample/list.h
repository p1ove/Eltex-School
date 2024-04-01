#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Item {
  int value;
  struct Item* next;
};

struct Item* InsertToStart(int newValue, struct Item* head);
struct Item* deleteFromStart(struct Item* head);
void deleteList(struct Item* head);
void printList(struct Item* head); //list_1

struct Item* InsertSort(int newValue, struct Item* head);//sort_list_1
struct Item* deleteValue(int value, struct Item* head) ;

#endif //LIST_H