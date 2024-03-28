#include "main.h"

int main() {
    char option = '0';
    while (option != '5') {
        menu(&option);
    }
    return 0;
}
