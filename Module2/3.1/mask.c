#include "main.h"

void mask(){
    char access_u[2];
    char access_g[2];
    char access_o[2];
    int result = 0;
    printf("Введите права доступа в буквенном или цифровом обозначении (например, rwx или 111): ");
    fgets(access_u,3,stdin);
    if (access_u[0]<'7' && access_u[0]>'0'){
        number_mask(access_u);
    }
    else{
        fgets(access_g,3,stdin);
        fgets(access_o,3,stdin);
        char **mass[2]={access_u,access_g,access_o};
        result = letter_mask(mass);
    }
}

int letter_mask(char**mass){
    int result = 0;
    for(int j = 0; j < 3; j++){
        for (int i = 0; i < strlen(mass[j][i]); i++) {
        switch (mass[j][i]) {
            case 'r':
                set_bit(result,3,1); // установить бит для чтения
                break;
            case 'w':
                set_bit(result,2,1); // установить бит для записи
                break;
            case 'x':
                set_bit(result,1,1); // установить бит для выполнения
                break;
            default:
                break;
        }
    }
    result = result << 3;
    }
    return result;
}

/*!
  \brief Функция, которая устанавливает бит в нужное значение
  \param[in] bit Получаемый разряд децимала -  bits[0], bits[1], bits[2],
  bits[3]
  \param[in] pos_bit  Позиция бита, отсчет идет от 1 до 32
  \param[in] num_zero_or_one  бит который нужно выставить 0 или 1
*/
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

/*!
  \brief Функция, которая возвращает 0 или 1 в зависимости от текущего бита.
  Если бит '0' то вернет - 0, если бит '1' то вернет - 1;
  \param[in] bit Получаемый разряд децимала -  bits[0], bits[1], bits[2],
  bits[3] \param[in] pos_bit  Позиция бита, отсчет идет от 1 до 32
*/
unsigned int get_bit(unsigned int bit, int pos_bit) {
  return (bit >> (--pos_bit)) & 1;
}
