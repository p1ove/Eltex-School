#include "main.h"

int parser(char* param){
    int flag_first_num = 0;
    int flag_sec_num = 0;
    int flag_th_num = 0;
    int i = 0;
    
    while (*param == 'u' || *param == 'g' || *param == 'o' || *param == 'a'){
        create_mask(param+i,*param);
        flag_first_num=1;
        i++;
        param++;
    }

    if (flag_first_num==0){
        create_mask(param+i,*param);
    }
}

void create_mask(char* param, char user){

    int rights = 7;
    int addition = 0;
    int minus = 1;

    while (*param == 'u' || *param == 'g' || *param == 'o' || *param == 'a'){
        param++;
    }

    if (*param == '-' || *param == '+' || *param == '='){
        param++;
        if (param == '-') minus = -1;
    }
    // else {
    //     return 1;
    // }
    while (*param == 'r' || *param == 'w' || *param == 'x'){
        if (*param =='r') addition+=4*minus;
        if (*param =='w') addition+=2*minus;
        if (*param =='x') addition+=1*minus;
    }

    switch(user){
    case 'u':

    break;
    case 'g':

    break;
    case 'o':

    break;
    case 'a':
    
    break;
    }

}