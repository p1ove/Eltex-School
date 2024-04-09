#include "main.h"

int main() {
  // struct contact book[100] = {0};
  struct contact* book = NULL;
  book = InsertValue(0, book);

  int option = 0;
  int person_id = 0;
  while (option != 4) {
    menu(&option, book, &person_id);
  }
  book = DeleteList(book);
  return 0;
}
