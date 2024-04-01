#include "main.h"

void delete (struct contact *book, int pid) {
  char name[30];
  int err = 1;
  while (err) {
    clear();
    print_book(book, pid);
    if (err == 2) {
      printf("Incorrect person name\n");
    }
    printf("Write person name\n");
    scanf("%s", name);
    for (int i = 0; i <= pid; i++) {
      if (strcmp(name, book[i].name.first_name) != 0) {
      } else {
        err = 0;
        *book[i].name.first_name = '\0';
        *book[i].name.last_name = '\0';
        *book[i].email.e1 = '\0';
        *book[i].email.e2 = '\0';
        *book[i].links.l1 = '\0';
        *book[i].links.l2 = '\0';
        *book[i].phone_numbers.n1 = '\0';
        *book[i].phone_numbers.n2 = '\0';
        *book[i].work.name = '\0';
        *book[i].work.post = '\0';
        break;
      }
      err = 2;
    }
  }
}