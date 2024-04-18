#include <stdio.h>

int main(int argc, char**argv){
    int summ = 0;
    for (int i = 1; i < argc; i++ ){
        summ += atoi(argv[i]);
    }
    printf("SUMMA:%d\n",summ);
    return 0;
}