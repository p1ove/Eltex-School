#include "list_2.h"

struct Item* InsertValue(int val, struct Item* head) {

struct Item* newItem;
struct Item* tmp = head;

newItem = malloc(sizeof(struct Item));
newItem->value = val;

// Вставка элемента в пустой список
if(NULL == head) {
newItem->prev = newItem;
newItem->next = newItem;
head = newItem;
return head;
}

// Вставка элемента в начало или середину списка
do {
if(newItem->value <= tmp->value) {
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

struct Item* DeleteValue(int val, struct Item* head) {

struct Item *tmp = head;
// Если пытаемся удалить элемент из пустого списка
if (NULL == head) {
printf("List empty!\n");
return head;
}
// Поиск и удаление элемента
do {
if (val == tmp->value) {
// Если удаляется единственный элемент списка
if(tmp->next == tmp->prev) {
free(tmp);
return NULL;
}
// Перестраиваем связи
tmp->next->prev = tmp->prev;
tmp->prev->next = tmp->next;
// Если элемент удаляется из начала списка, изменяем head
if(tmp == head) head = head->next;
// Удаляем найденный элемент
free(tmp);
return head;
}
tmp = tmp->next;
} while (tmp != head);
// Если элемент не найден, выводим сообщение
printf("List does not contain %d!\n", val);
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
printf ("%d ", tmp->value);
tmp = tmp->next;
} while (tmp != head);
printf("\n");
}

int main(){
struct Item* head = NULL;
head = InsertValue(10, head);
head = InsertValue(1, head);
head = InsertValue(100, head);
head = InsertValue(50, head);
PrintList(head);
head = DeleteValue(100, head);
head = DeleteValue(0, head);
head = DeleteValue(10, head);
head = DeleteValue(100, head);
PrintList(head);
head = DeleteList(head);
PrintList(head);
return 0;
}