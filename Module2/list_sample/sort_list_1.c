#include "list.h"

struct Item* InsertSort(int newValue, struct Item* head) {

struct Item* item = malloc(sizeof(struct Item));
item->value = newValue;
item->next = NULL;

struct Item* tmp = head;

if(head == NULL) return item;

if(newValue < head->value) {
item->next = head;
return item;
}

while(tmp->next != NULL) {
    if(newValue < tmp->next->value) {
  item->next = tmp->next;
  tmp->next = item;
  break;
}

  else tmp = tmp->next;
}

  tmp->next = item;
  return head;
}

struct Item* deleteValue(int value, struct Item* head) {
    
struct Item* prev = head;
struct Item* item;

if (head == NULL) return NULL;

if (head->value == value) {
  item = head;
  head = head->next;
  free(item);
  return head;
}

while (prev->next != NULL) {
  if (prev->next->value == value) {
  item = prev->next;
  prev->next = prev->next->next;
  free(item);
  return head;
  }
  else prev = prev->next;
}

return head;
}

// int main() {
// struct Item* head = NULL;
// head = InsertSort(100, head);
// head = InsertSort(90, head);
// head = InsertSort(110, head);
// head = InsertSort(20, head);
// printList(head);
// deleteList(head);
// return 0;
// }

int main(){
struct Item* head = NULL;
head = InsertSort(90, InsertSort(100, InsertSort(110, head)));
head = deleteValue(20, head);
head = deleteValue(100, head);
head = deleteValue(110, head);
printList(head);
deleteList(head);
return 0;
}