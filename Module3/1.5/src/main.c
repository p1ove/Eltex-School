#include "lib_src/main.h"

int main() {

  struct contact* book = NULL;
  book = InsertValue(0, book);
  book = InsertValue(1, book);

  int option = 0;
  int person_id = 0;

  while (option != 4) {
    menu(&option, book, &person_id);
  }

  write_list(book);

  book = DeleteList(book);
  return 0;
}
