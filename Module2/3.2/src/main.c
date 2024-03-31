#include "main.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Использование: %s <IP адрес шлюза> <Маска подсети> <Количество пакетов>\n", argv[0]);
        return 1;
    }

    const char *gateway = argv[1];
    const char *subnet_mask = argv[2];
    int num_packets = atoi(argv[3]);

    srand(time(NULL));

    int same_subnet_count = 0;
    int different_subnet_count = 0;

    for (int i = 0; i < num_packets; i++) {
        // Генерируем случайный IP-адрес
        char random_ip[INET_ADDRSTRLEN];
        sprintf(random_ip, "%d.%d.%d.%d", rand() % 256, rand() % 256, rand() % 256, rand() % 256);

        // Определяем, принадлежит ли случайный IP-адрес той же подсети, что и шлюз
        if (is_same_subnet(random_ip, gateway, subnet_mask)) {
            same_subnet_count++;
        } else {
            different_subnet_count++;
        }
    }

    printf("Статистика:\n");
    printf("Пакетов для своей подсети: %d (%.2f%%)\n", same_subnet_count, 
        (float)same_subnet_count / num_packets * 100);
    printf("Пакетов для других подсетей: %d (%.2f%%)\n", different_subnet_count, 
        (float)different_subnet_count / num_packets * 100);

    return 0;
}
