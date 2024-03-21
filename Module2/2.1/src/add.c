#include "main.h"

void add(contact *book, int *pid) {
  int choice = 0;
  // printf("PID %d\n", *pid);
  clear();
  printf("Write first name\n");
  //scanf("%s", book[*pid].name.first_name);
  fgets(book[*pid].name.first_name, 20, stdin);

  printf("Write last name\n");
  //scanf("%s", book[*pid].name.last_name);
   fgets(book[*pid].name.last_name, 20, stdin);
  printf("Do you want to continue?\n");
  printf("1-YES\n");
  printf("0-NO\n");
  //scanf("%d", &choice);
  if (choice == 1) {
    printf("Write work name\n");
    // scanf("%s", book[*pid].work.name);
       fgets(book[*pid].work.name, 20, stdin);
    printf("Write work post\n");
    fgets(book[*pid].work.post, 20, stdin);

    printf("Write phone number 1\n");
    // scanf("%s", book[*pid].phone_numbers.n1);
    fgets(book[*pid].phone_numbers.n1, 20, stdin);
    printf("Write phone number 2\n");
    // scanf("%s", book[*pid].phone_numbers.n2);
    fgets(book[*pid].phone_numbers.n2, 20, stdin);


    printf("Write email\n");
    // scanf("%s", book[*pid].email);
    fgets(book[*pid].email, 20, stdin);

    printf("Write link 1\n");
    // scanf("%s", book[*pid].links.l1);
    fgets(book[*pid].links.l1, 20, stdin);

    printf("Write link 2\n");
    // scanf("%s", book[*pid].links.l2);
    fgets(book[*pid].links.l2, 20, stdin);

  }
  *pid += 1;
}