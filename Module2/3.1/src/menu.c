#include "main.h"

void option_action(int opt,int* result) {

  switch (opt) {
  case 1:
    *result = mask();
    break;
  case 2:
    *result = file_mask();
    break;
  case 3:
    if(*result){
      change_rights(*result);
    }
    else{
      printf("Сначала укажите файл или права\n");
    }
    break;
  case 4:
    break;
  default:
    break;
  }
}

void menu(int *option,int *result) {
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
  option_action(*option,result);
}