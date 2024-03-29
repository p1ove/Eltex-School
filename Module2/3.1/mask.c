#include "main.h"
#include <string.h>

void mask(){
    char access_u[3];
    char access_g[3];
    char access_o[3];
    int result = 0;
    printf("Введите права доступа в буквенном или цифровом обозначении (например, rwx или 111): ");
    fgets(access_u,4,stdin);
    printf("gdfgsdf%s\n",access_u);
    if (access_u[0]<'8' && access_u[0]>='0'){
        result = number_mask(access_u);
        printf("gdfgsdf%s\n",access_u);
    }
    else{
        fgets(access_g,4,stdin);
        fgets(access_o,4,stdin);
        letter_mask(access_u,&result,0);
        letter_mask(access_g,&result,3);
        letter_mask(access_o,&result,6);
    }
 // print_bits(result);
}

void print_bits(int a){
  for(int i = 0; i < 9; i++){
    printf("%d ",(a>>i)&1);
  }
}

int number_mask(char* mask){
  int res = 0;
  int ugo[3] = {0};

  for (int i = 0; i < 3; i++){
    ugo[i] = *(mask+i)-'0';
    printf("%d\n",ugo[i]);
  }

for(int j = 0; j < 3;j++){
  for (int i = 0; i < 3; i++){
    int bit = get_bit(ugo[j],i*(j+1));
    set_bit(res,i*(j+1),bit);
  }
}
  return res;
}

int letter_mask(char* u,int* a,int num){
    int result = 0;
        for (int i = 0; i < 3; i++) {
        switch (*(u+i)) {
            case 'r':
                set_bit(result,3+num,1); // установить бит для чтения
                break;
            case 'w':
                set_bit(result,2+num,1); // установить бит для записи
                break;
            case 'x':
                set_bit(result,1+num,1); // установить бит для выполнения
                break;
            default:
                break;
        }
    }
    return result;
}

void set_bit(int *bit, int pos_bit, short num_zero_or_one) {
  int digits_32[32] = {0};
  for (int i = 0; i < 32; i++) {
    digits_32[i] = 1 << i;
  }
  if (num_zero_or_one)
    *bit |= digits_32[pos_bit - 1];
  else
    *bit &= ~digits_32[pos_bit - 1];
}

int get_bit(int bit, int pos_bit) {
  return (bit >> (--pos_bit)) & 1;
}

int main(){
  mask();
  return 0;
}