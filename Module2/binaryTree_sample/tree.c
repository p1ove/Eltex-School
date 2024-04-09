#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

typedef struct btree {
int value;
struct btree *left, *right;
} btree;

// Поиск с включением
void Ins_Btree(int val, btree **q) {
if(*q == NULL) {
*q = malloc(sizeof(btree));
(*q)->left = (*q)->right = NULL;
(*q)->value = val;
return;
}
if((*q)->value > val)
Ins_Btree(val, &(*q)->left);
else
Ins_Btree(val, &(*q)->right);
}

// Печать содержимого дерева
void Print_Btree(btree *p) {
if (p == NULL) return;
Print_Btree(p->left);
printf("%d ", p->value);
Print_Btree(p->right);
}

// Удаление вершины с заданным значением key
int Delete(int key, btree **node) {
btree *t, *up;
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

int main() {
int d[] = {50,30,55,25,35,53,60,10,32,37,62,15,31,33,40,0};
int i = 0;
btree *root = NULL;
printf("Array (end - 0):\n");
while(1) {
if(d[i] == 0) break;
Ins_Btree(d[i], &root); i++;
}
Print_Btree(root); printf("\n");
Delete(50, &root);
printf("After Delete:\n");
Print_Btree(root); printf("\n");
return 0;
}