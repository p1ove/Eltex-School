#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Функция для конвертации буквенного обозначения в битовое представление
int access_to_bits(char access[]) {
    int result = 0;
    for (int i = 0; i < strlen(access); i++) {
        switch (access[i]) {
            case 'r':
                result |= 4; // установить бит для чтения
                break;
            case 'w':
                result |= 2; // установить бит для записи
                break;
            case 'x':
                result |= 1; // установить бит для выполнения
                break;
            default:
                break;
        }
    }
    return result;
}

// Функция для отображения битового представления в буквенное обозначение
void bits_to_access(int bits) {
    printf("Битовое представление: %d%d%d\n", (bits & 4) ? 1 : 0, (bits & 2) ? 1 : 0, (bits & 1) ? 1 : 0);
    printf("Буквенное обозначение: ");
    if (bits & 4)
        printf("r");
    if (bits & 2)
        printf("w");
    if (bits & 1)
        printf("x");
    printf("\n");
}

int main() {
    char access[4];
    printf("Введите права доступа в буквенном или цифровом обозначении (например, rwx или 111): ");
    scanf("%s", access);

    int bits;
    if (strlen(access) == 3 && access[0] >= '0' && access[0] <= '1' && access[1] >= '0' && access[1] <= '1' && access[2] >= '0' && access[2] <= '1') {
        bits = atoi(access);
    } else {
        bits = access_to_bits(access);
    }

    bits_to_access(bits);

    return 0;
}
