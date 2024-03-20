#include "main.h"

void option_action(int opt, contact *book, int *person_id) {

  switch (opt) {
  case 1:
    add(book, person_id);
    break;
  case 2:
    edit(book, *person_id);
    break;
  case 3:
    delete (book, *person_id);
    break;
  case 4:
    break;
  case 5:
    print_book(book, *person_id);
    break;
  default:
    break;
  }
}