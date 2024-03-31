#include "main.h"

void option_action(int opt) {

  switch (opt) {
  case 1:
    mask();
    break;
  case 2:
    file_mask();
    break;
  case 3:
    
    break;
  case 4:
    break;
  default:
    break;
  }
}

void menu(int *option) {
  // clear();
  if (*option > 5 || *option < 0) {
    printf("***\n");
    printf("Please choose right option\n");
    printf("***\n");
  }
  printf("Select an action\n");
  printf("1: Битовое представление прав доступа\n");
  printf("2: Узнать права доступа к файлу\n");
  printf("3: Изменить права доступа из пунктов 1-2\n");
  printf("4: Выход\n");

  scanf("%d",option);
  option_action(*option);
}