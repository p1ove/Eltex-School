#include "queue.h"

struct Item* InsertSort(char* value, int prior, struct Item* head) {

struct Item* item = malloc(sizeof(struct Item));
item->priority = prior;
strcpy(item->value,value);
item->next = NULL;

struct Item* tmp = head;

if(head == NULL){
item->prev = NULL;
return item;
}

if(prior < head->priority) {
item->next = head;
head->prev = item;
return item;
}

while(tmp->next != NULL) {
    if(prior < tmp->next->priority) {
  item->next = tmp->next;
  item->prev = tmp;
  tmp->next = item;
  break;
}
  else tmp = tmp->next;
}

  tmp->next = item;
  return head;
}

struct Item* deleteValue(int priority, struct Item* head) {
    
struct Item* prev = head;
struct Item* item;

if (head == NULL) return NULL;

if (head->priority >= priority) {
  item = head;
  head = head->next;
  free(item);
  return head;
}

while (prev->next != NULL) {
  if (prev->next->priority >= priority) {
  item = prev->next;
  prev->next = prev->next->next;
 // prev->next->prev = prev->next;
  free(item);
  return head;
  }
  else prev = prev->next;
}

return head;
}
void deleteList(struct Item* head) {
    for(struct Item* item = head; item != NULL; item = head) {
        head = head->next;
        free(item);
    }
}

void printList(struct Item* head) {
    for(struct Item* item = head; item != NULL; item = item->next) {
        printf("%s(%d) ", item->value,item->priority);
    }
    printf("\n");
}