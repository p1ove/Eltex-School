#include "main.h"

int main() {
  struct contact book[100] = {0};
  int option = 0;
  int person_id = 0;
  while (option != 4) {
    menu(&option, book, &person_id);
  }
  return 0;
}