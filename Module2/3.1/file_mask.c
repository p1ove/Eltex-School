#include "main.h"


void file_mask(){
    char filename[256];
    printf("Введите имя файла: ");
    getchar();//перехват \n из потока после scanf
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    printf("Права доступа для файла \"%s\":\n", filename);
    get_file_permissions(filename);
}

void get_file_permissions(const char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        perror("Ошибка при получении информации о файле");
        return;
    }

    printf("Буквенное представление: ");
    printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
    printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    printf("Цифровое представление: %o\n", file_stat.st_mode & 0777);

    printf("Битовое представление:\n");
    print_bits((int)file_stat.st_mode);
}