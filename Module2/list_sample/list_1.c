#include <stdio.h>
#include <stdlib.h>

struct Item {
  int value;
  struct Item* next;
};


struct Item* InsertToStart(int newValue, struct Item* head) {
    struct Item* newItem = malloc(sizeof(struct Item));
    newItem->value = newValue;
    newItem->next = head;
    return newItem;
}

struct Item* deleteFromStart(struct Item* head) {
    struct Item* item = head;
        if(item != NULL) {
            head = head->next;
            free(item);
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
        printf("%d ", item->value);
    }
    printf("\n");
}

// int main() {

//   struct Item* head = NULL;

//   head = InsertToStart(100, head);
//   head = InsertToStart(90, head);
//   head = InsertToStart(10, head);
//   printList(head);

//   head = deleteFromStart(head);
//   printList(head);

//   deleteList(head);
// return 0;
// }