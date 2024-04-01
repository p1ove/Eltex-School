#include "main.h"

void delete (struct contact *book, int pid) {
  // char name[30];

  struct contact * temp = book;

  int id = 0;
  int err = 1;
  while (err) {
    clear();
    PrintList(book);
    if (err == 2) {
      printf("Incorrect person id\n");
    }
    printf("Write person id\n");
    scanf("%d", &id);
    for (  ;id <= pid; id++) {
      // if (strcmp(name, book.name.first_name) != 0) {
        if (id != book->id) {
      } else {
        err = 0;
        DeleteValue(id,book);
        book = temp;
        // *book.name.first_name = '\0';
        // *book.name.last_name = '\0';
        // *book.email.e1 = '\0';
        // *book.email.e2 = '\0';
        // *book.links.l1 = '\0';
        // *book.links.l2 = '\0';
        // *book.phone_numbers.n1 = '\0';
        // *book.phone_numbers.n2 = '\0';
        // *book.work.name = '\0';
        // *book.work.post = '\0';
        break;
      }
      if(err)book = book->next;
      err = 2;
    }
  }
}