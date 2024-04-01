#include "main.h"

void print_book(struct contact *book, int pid) {
  printf("PHOHE BOOK:\n");
  for (int i = 0; i <= pid; i++) {
    printf("%s, %s\n", book[i].name.first_name, book[i].name.last_name);
    if (*book[i].work.name == 0)
      continue;
    else {
      printf("%s; ", book[i].work.name);
      printf("%s; ", book[i].work.post);
      printf("%s; ", book[i].phone_numbers.n1);
      printf("%s; ", book[i].phone_numbers.n2);
      printf("%s; ", book[i].email.e1);
      printf("%s; ", book[i].email.e2);
      printf("%s; ", book[i].links.l1);
      printf("%s; \n", book[i].links.l2);
    }
  }
}

void clear() { printf("\033[0d\033[2J"); }