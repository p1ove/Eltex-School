#include "main.h"

// Поиск с включением
void InsertValue(int val, contact **q) {
if(*q == NULL) {
*q = malloc(sizeof(contact));
(*q)->left = (*q)->right = NULL;
(*q)->value = val;
if (val) scan_val(*q);
return;
}
if((*q)->value > val){
InsertValue(val, &(*q)->left);
}
else{
InsertValue(val, &(*q)->right);
}
}

// Печать содержимого дерева
void PrintList (contact *p) {
if (p == NULL) return;
PrintList(p->left);
if(p->value){
    printf("id(%d)%s, %s\n",p->value, p->name.first_name, p->name.last_name);
}
if (strlen(p->work.name)>1){
      printf("%s; ", p->work.name);
      printf("%s; ", p->work.post);
      printf("%s; ", p->phone_numbers.n1);
      printf("%s; ", p->phone_numbers.n2);
      printf("%s; ", p->email.e1);
      printf("%s; ", p->email.e2);
      printf("%s; ", p->links.l1);
      printf("%s; \n", p->links.l2);
}
PrintList(p->right);
}

// Удаление вершины с заданным значением key
int Delete(int key, contact **node) {
contact *t, *up;
if(*node == NULL) return 0; // нет такого значения в дереве
if((*node)->value == key) {
// если значение находится в листе, то удаляем лист
if(((*node)->left == NULL) && ((*node)->right == NULL)) {
free(*node);
*node = NULL;
printf("Delete List\n");
return 1;
}

// если у вершины только правый потомок, то перебрасываем
// связь на вершину ниже удаляемой в правом поддереве
if((*node)->left == NULL) {
t = *node;
*node =(*node)->right;
free(t);
printf("Delete Left = 0\n");
return 1;
}

// если у вершины только левый потомок, то перебрасываем
// связь на вершину ниже удаляемой в левом поддереве
if((*node)->right == NULL) {
t = *node;
*node =(*node)->left;
free(t);
printf("Delete Right = 0\n");
return 1;
}

// если у вершины два потомка, то заменяем удаляемое значение
// на значение самого правого элемента в левом поддереве
up = *node;
t = (*node)->left; // идем в левое поддерево
//спускаемся до крайнего правого узла
while (t->right != NULL) {
up = t;
t = t-> right;
}
//копируем значение из правого узла вместо удаляемого значения
(*node)->value = t->value;

// если ниже удаляемого больше, чем одна вершина
if (up != (*node)) {
// если крайний правый не лист, то «отбрасываем» его из дерева
if(t->left != NULL) up->right = t->left;
else up->right = NULL; // удаляем лист
}
// если ниже удаляемого одна вершина, удаляем лист
else (*node)->left = t->left;
// освобождаем память – удаляем крайнюю
// правую вершину
free(t);
printf("Delete Two\n");
return 1;
}

// поиск ключа в левом или правом поддереве
if((*node)->value < key)
return Delete(key, &(*node)->right);
return Delete(key, &(*node)->left);
}