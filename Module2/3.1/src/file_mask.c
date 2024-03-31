#include "main.h"


int file_mask(){
    char filename[256];
    printf("Введите имя файла: ");
    getchar();//перехват \n из потока после scanf
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    printf("Права доступа для файла \"%s\":\n", filename);
    return get_file_permissions(filename);
}

int get_file_permissions(const char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        perror("Ошибка при получении информации о файле");
        return 0;
    }

    print_bykva(file_stat.st_mode);

    printf("Цифровое представление: %o\n", file_stat.st_mode & 0777);

    printf("Битовое представление:\n");
    print_bits((int)file_stat.st_mode);
    return file_stat.st_mode & 0777;
}