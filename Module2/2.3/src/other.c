#include "main.h"

void scan_values(int* a, int* b){
    printf("Введите два числа для операции\n");
    scanf("%d",a);
    scanf("%d",b);
    // char newline; если используются fgets или getc
    // while ((newline = getchar()) != '\n' && newline != EOF);// читстка потока ввода после scanf
}

void option_action(int opt) {

  void (*arithmetic[])(int,int)={summ,sub,mult,dev};
  int a = 0,b = 0;
  if (opt>0 && opt<5){
    scan_values(&a,&b);
    arithmetic[opt-1](a,b);
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
  printf("1: Summ\n");
  printf("2: Sub\n");
  printf("3: Mult\n");
  printf("4: Dev\n");
  printf("5: Exit\n");

  scanf("%d",option);
  option_action(*option);
}