#include "main.h"

void mask(){
    char access_u[4];
    char access_g[4];
    char access_o[4];
    int result = 0;
    printf("Введите права доступа в буквенном обозначении (rwx-) для пользователя,\n");
    printf("Или цифровом обозначении (777) для всех: \n");
    getchar();//перехват \n из потока после scanf
    fgets(access_u,4,stdin);
    if (access_u[0]<'8' && access_u[0]>='0'){
        result = number_mask(access_u);
    }
    else{
        getchar();//перехват \n из потока после fgets
        printf("Введите права доступа в буквенном обозначении для группы: ");
        fgets(access_g,4,stdin);
        getchar();//перехват \n из потока после fgets
        printf("Введите права доступа в буквенном обозначении для остальных: ");
        fgets(access_o,4,stdin);
        letter_mask(access_u,&result,6);
        letter_mask(access_g,&result,3);
        letter_mask(access_o,&result,0);
    }
 printf("Битовое представление прав доступа:\n");
 print_bits(result);
}

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

int number_mask(char* mask){
  int res = 0;
  int ugo[3] = {0};

  for (int i = 0; i < 3; i++){
    ugo[i] = *(mask+i)-'0';
  }

for(int j = 0; j < 3;j++){
  for (int i = 0; i < 3; i++){
    int bit = get_bit(ugo[j],i+1);
    res=res<<1;
    if(bit)res|=1;
  }
}
  return res;
}

int letter_mask(char* u,int* a,int num){
    int result = 0;
        for (int i = 0; i < 3; i++) {
        switch (*(u+i)) {
            case 'r':
                set_bit(a,3+num,1); // установить бит для чтения
                break;
            case 'w':
                set_bit(a,2+num,1); // установить бит для записи
                break;
            case 'x':
                set_bit(a,1+num,1); // установить бит для выполнения
                break;
            default:
                break;
        }
    }
    return result;
}

void set_bit(int *number, int pos_bit, short bit) {
  int bits_32[32] = {0};
  for (int i = 0; i < 32; i++) {
    bits_32[i] = 1 << i;
  }
  if (bit)
    *number |= bits_32[pos_bit - 1];
  else
    *number &= ~bits_32[pos_bit - 1];
}

int get_bit(int bit, int pos_bit) {
  return (bit >> (--pos_bit)) & 1;
}