#include "main.h"

void add(contact *book, int *pid) {
  int choice = 0;
  // printf("PID %d\n", *pid);
  clear();
  printf("Write first name\n");
  scanf("%s", book[*pid].name.first_name);
  printf("Write last name\n");
  scanf("%s", book[*pid].name.last_name);
  printf("Do you want to continue?\n");
  printf("1-YES\n");
  printf("0-NO\n");
  scanf("%d", &choice);
  if (choice == 1) {
    printf("Write work name\n");
    scanf("%s", book[*pid].work.name);
    printf("Write work post\n");
    scanf("%s", book[*pid].work.post);

    printf("Write phone number 1\n");
    scanf("%s", book[*pid].phone_numbers.n1);
    printf("Write phone number 2\n");
    scanf("%s", book[*pid].phone_numbers.n2);

    printf("Write email\n");
    scanf("%s", book[*pid].email);

    printf("Write link 1\n");
    scanf("%s", book[*pid].links.l1);
    printf("Write link 2\n");
    scanf("%s", book[*pid].links.l2);
  }
  *pid += 1;
}