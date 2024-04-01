#include "main.h"

void add(struct contact *book, int *pid) {
  // if (*pid > 0){
    book = InsertValue(*pid+1, book);
  // }
  int choice = 0;
  // printf("PID %d\n", *pid);
  // book->id = *pid;
  clear();
  printf("Write first name\n");
  scanf("%s", book->name.first_name);
  printf("Write last name\n");
  scanf("%s", book->name.last_name);
  printf("Do you want to continue?\n");
  printf("1-YES\n");
  printf("0-NO\n");
  scanf("%d", &choice);
  if (choice == 1) {
    printf("Write work name\n");
    scanf("%s", book->work.name);
    printf("Write work post\n");
    scanf("%s", book->work.post);

    printf("Write phone number 1\n");
    scanf("%s", book->phone_numbers.n1);
    printf("Write phone number 2\n");
    scanf("%s", book->phone_numbers.n2);

    printf("Write email 1\n");
    scanf("%s", book->email.e1);
    printf("Write email 2\n");
    scanf("%s", book->email.e2);

    printf("Write link 1\n");
    scanf("%s", book->links.l1);
    printf("Write link 2\n");
    scanf("%s", book->links.l2);
  }
  *pid += 1;
}