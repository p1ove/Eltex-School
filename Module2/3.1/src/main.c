#include "main.h"

int main() {
    int option = 0;
    int result_action = 0;
    while (option != 4) {
        menu(&option,&result_action);
    }
    return 0;
}
