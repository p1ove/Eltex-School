#include "queue.h"

int main(){
struct Item* head = NULL;
head = InsertSort("11",1, head);
head = InsertSort("21",1, head);
head = InsertSort("31",1, head);
head = InsertSort("41",0, head);
head = InsertSort("51",1, head);
head = InsertSort("61",1, head);
head = InsertSort("71",1, head);

printList(head);
// int delres = 0;
// int delprior = 0;
head = deleteValue(/*&delres,*/1, head);
printList(head);// printf("%d\n",delres);
head = deleteValue(/*&delres,*/1, head);
printList(head);// printf("%d\n",delres);
head = deleteValue(/*&delres,*/1, head);
printList(head);// printf("%d\n",delres);
head = deleteValue(/*&delres,*/1, head);
printList(head);// printf("%d\n",delres);
head = deleteValue(/*&delres,*/1, head);
printList(head);// printf("%d\n",delres);
head = deleteValue(/*&delres,*/1, head);
printList(head);// printf("%d\n",delres);
head = deleteValue(/*&delres,*/1, head);
printList(head);// printf("%d\n",delres);
head = deleteValue(/*&delres,*/1, head);
printList(head);// printf("%d\n",delres);
deleteList(head);
// printList(head);
return 0;
}