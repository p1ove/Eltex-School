#include "queue.h"

struct Item* InsertValue(int val, int prio, struct Item* head) {

struct Item* newItem;
struct Item* tmp = head;

newItem = malloc(sizeof(struct Item));
newItem->val = val;
newItem->priority = prio;

// Вставка элемента в пустой список
if(NULL == head) {
newItem->prev = newItem;
newItem->next = newItem;
head = newItem;
return head;
}

//Вставка элемента в начало или середину списка
do {
if(newItem->priority < tmp->priority) {
newItem->next = tmp;
newItem->prev = tmp->prev;
tmp->prev->next = newItem;
tmp->prev = newItem;
if(tmp == head) head = newItem;
return head;
}
tmp = tmp->next;
} while(tmp != head);

// Вставка элемента в конец списка
newItem->next = tmp;
newItem->prev = tmp->prev;
tmp->prev->next = newItem;
tmp->prev = newItem;
return head;

}

struct Item* DeleteValue(int* res,int prior, struct Item* head) {

struct Item *tmp = head;
// Если пытаемся удалить элемент из пустого списка
if (NULL == head) {
printf("List empty!\n");
return head;
}

do {
if (prior == tmp->priority) {
// Если удаляется единственный элемент списка
if(tmp->next == tmp->prev) {
*res = tmp->val;
free(tmp);
return NULL;
}
// Перестраиваем связи
tmp->next->prev = tmp->prev;
tmp->prev->next = tmp->next;
// Если элемент удаляется из начала списка, изменяем head
if(tmp == head) head = head->next;
// Удаляем найденный элемент
*res = tmp->val;
free(tmp);
return head;
}
tmp = tmp->next;
} while (tmp != head);
*res = tmp->val;
free(tmp);
return head;
}

struct Item* DeleteList(struct Item* head) {

  struct Item* tmp = head;
  struct Item* itemForRemove;

if (NULL == head) {
return NULL;
}
do {
itemForRemove = tmp;
tmp = tmp->next;
free(itemForRemove);
} while (tmp != head);
return NULL;
}

void PrintList(struct Item* head) {
struct Item* tmp = head;
if (NULL == head) {
printf("List empty!\n");
return;
}
do {
printf ("%d ", tmp->val);
tmp = tmp->next;
} while (tmp != head);
printf("\n");
}

int main(){
struct Item* head = NULL;
head = InsertValue(10,1, head);
head = InsertValue(1,1, head);
head = InsertValue(100,1, head);
head = InsertValue(50,0, head);
head = InsertValue(40,1, head);
head = InsertValue(30,1, head);
head = InsertValue(20,1, head);

PrintList(head);
int delres = 0;
head = DeleteValue(&delres, head);
PrintList(head); printf("%d\n",delres);
head = DeleteValue(&delres, head);
PrintList(head); printf("%d\n",delres);
head = DeleteValue(&delres, head);
PrintList(head); printf("%d\n",delres);
head = DeleteValue(&delres, head);
PrintList(head); printf("%d\n",delres);
head = DeleteList(head);
// PrintList(head);
return 0;
}