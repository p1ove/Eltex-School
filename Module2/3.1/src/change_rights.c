#include "main.h"

void change_rights(int res){
    char param[15] = {0};
    int minus = 0;
    printf("Введите изменения прав доступа: ");
    // getchar();
    // fgets(param,14,stdin);
    scanf("%s",param);
    int mask = pars_user(param,&minus);
    printf("Прежние права доступа:\n");
    print_bits(res);
    // printf("Маска изменения прав:\n");
    // print_bits(mask);
    if(minus){
        res&=mask;
    }
    else{
        res|=mask;
    }
    printf("Новые права доступа:\n");
    print_bits(res);
    print_numbers(res);
    print_bykva(res);
}


int pars_user(char* param,int* minus){
    int user = 0;
    int i = 0;
    int mask = 0;

    while (*param == 'u' || *param == 'g' || *param == 'o' || *param == 'a'){
        create_mask(param+i,*param,&mask,minus);
        user=1;
        i++;
        param++;
    }

    if (user==0){
        create_mask(param+i,'u',&mask,minus);
    }
    return mask;
}

void create_mask(char* param, char user, int* main_mask,int *minus){

    *minus = 0;

    while (*param == 'u' || *param == 'g' || *param == 'o' || *param == 'a'){
        param++;
    }

    if (*param == '-' || *param == '+' || *param == '='){
        if (*param == '-') *minus = 1;
        param++;
    }
    else {
        *main_mask = 0;
        return;
    }

    int mask = 0777;
    if(!*minus){
        mask = 0;
    }

    while (*param == 'r' || *param == 'w' || *param == 'x'){
        if (*param =='r'){
           if(*minus) set_bit(&mask,3,0);
            else set_bit(&mask,3,1);
        }
        if (*param =='w'){
           if(*minus) set_bit(&mask,2,0);
            else set_bit(&mask,2,1);
        }
        if (*param =='x'){
              if(*minus) set_bit(&mask,1,0);
            else set_bit(&mask,1,1);
        }
        param++;
    }

    switch(user){
    case 'u':
    if(*minus)*main_mask|=(mask<<6)|077;
    else *main_mask|=(mask<<6);
    break;
    case 'g':
    if(*minus)*main_mask|=(mask<<3)|07;
    else *main_mask|=(mask<<3);
    break;
    case 'o':
    *main_mask|=mask;
    break;
    case 'a':
    *main_mask|=mask;
    *main_mask|=(mask<<3)|07;
    *main_mask|=(mask<<6)|077;
    break;
    }
}