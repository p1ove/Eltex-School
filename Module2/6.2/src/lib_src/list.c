#include "main.h"

struct contact* InsertValue(int val, struct contact* head) {

struct contact* newItem;
struct contact* tmp = head;

newItem = malloc(sizeof(struct contact));
newItem->id = val;

// Вставка элемента в пустой список
if(NULL == head) {
newItem->prev = newItem;
newItem->next = newItem;
head = newItem;
return head;
}

// Вставка элемента в начало или середину списка
do {
if(newItem->id <= tmp->id) {
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

scan_val(newItem);

return head;

}

struct contact* DeleteValue(int val, struct contact* head) {

struct contact *tmp = head;
// Если пытаемся удалить элемент из пустого списка
if (NULL == head) {
printf("List empty!\n");
return head;
}
// Поиск и удаление элемента
do {
if (val == tmp->id) {
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

struct contact* DeleteList(struct contact* head) {

  struct contact* tmp = head;
  struct contact* itemForRemove;

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

void PrintList(struct contact* head) {
struct contact* tmp = head;
if (NULL == head) {
printf("List empty!\n");
return;
}
do {
//printf ("%d ", tmp->id);
if(tmp->id){
    printf("id(%d)%s, %s\n",tmp->id, tmp->name.first_name, tmp->name.last_name);
}
if (strlen(tmp->work.name)>1){
      printf("%s; ", tmp->work.name);
      printf("%s; ", tmp->work.post);
      printf("%s; ", tmp->phone_numbers.n1);
      printf("%s; ", tmp->phone_numbers.n2);
      printf("%s; ", tmp->email.e1);
      printf("%s; ", tmp->email.e2);
      printf("%s; ", tmp->links.l1);
      printf("%s; \n", tmp->links.l2);
}
tmp = tmp->next;
} while (tmp != head);
printf("\n");
}