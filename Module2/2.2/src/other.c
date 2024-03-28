#include "main.h"

void scan_values(int* a, int* b){
    printf("Введите два числа для операции\n");
    scanf("%d",a);
    scanf("%d",b);
    char newline;
    while ((newline = getchar()) != '\n' && newline != EOF);//читстка потока ввода после scanf
}

void option_action(char opt) {

  int a = 0,b = 0;

  switch (opt) {
  case '1':
    scan_values(&a,&b);
    summ(a,b);
    break;
  case '2':
    scan_values(&a,&b);
    sub(a,b);
    break;
  case '3':
    scan_values(&a,&b);
    mult(a,b);
    break;
  case '4':
    scan_values(&a,&b);
    dev(a,b);
    break;
  case '5':
    break;
  default:
    break;
  }
}

void menu(char *option) {
  // clear();
  if (*option > 5+'0' || *option < '0') {
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

  *option = getchar();
  option_action(*option);
}