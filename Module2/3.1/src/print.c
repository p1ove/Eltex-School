#include "main.h"

void print_bits(int a){
  char* person[3]={"user","group","other"};
  int n = 0;

  for(int i = 8; i >= 0; i--){
    printf("%d ",(a>>i)&1);
    if((i%3) == 0){
      printf("%s\n",person[n]);
      n++;
    }
  }
}

void print_numbers(int a){
    printf("Числовое представление: %o %o %o\n",(a>>6)&07,(a>>3)&07,a&07);
}

void print_bykva(int a){
    printf("Буквенное представление: ");
    printf((a & S_IRUSR) ? "r" : "-");
    printf((a & S_IWUSR) ? "w" : "-");
    printf((a & S_IXUSR) ? "x" : "-");
    printf((a & S_IRGRP) ? "r" : "-");
    printf((a & S_IWGRP) ? "w" : "-");
    printf((a & S_IXGRP) ? "x" : "-");
    printf((a & S_IROTH) ? "r" : "-");
    printf((a & S_IWOTH) ? "w" : "-");
    printf((a & S_IXOTH) ? "x" : "-");
    printf("\n");
}