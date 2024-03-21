#include "main.h"

void menu(int *option, contact *book, int *person_id) {
  // clear();
  if (*option > 5 || *option < 0) {
    printf("***\n");
    printf("Please choose right option\n");
    printf("***\n");
  }
  printf("Select an action\n");
  printf("1: Add contact\n");
  printf("2: Edit contact\n");
  printf("3: Delete contact\n");
  printf("4: Exit\n");
  printf("5: See book\n");

  *option = getchar();
  option_action(*option, book, person_id);
}