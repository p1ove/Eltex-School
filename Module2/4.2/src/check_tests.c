#include "tests.h"

#define NUM_MESSAGES 50

START_TEST(test_insert_sort) {
    struct Item* head = NULL;

    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Создание и вставка случайных сообщений
    for (int i = 0; i < NUM_MESSAGES; i++) {
        char value[10];
        sprintf(value, "%d", i);
        int priority = rand() % 256; // Генерация случайного приоритета от 0 до 255
        head = InsertSort(value, priority, head);
    }
    printf("\nУпорядоченная по приоритетам(n) очередь:\n\n");
    printList(head);
    // Проверка, что сообщения были вставлены в правильном порядке
    int prev_priority = -1;
    for (struct Item* item = head; item != NULL; item = item->next) {
        ck_assert_int_ge(item->priority, prev_priority);
        prev_priority = item->priority;
    }

    // Очистка памяти
    deleteList(head);
}
END_TEST

START_TEST(test_delete_value_priority) {
    struct Item* head = NULL;

    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Создание и вставка случайных сообщений
    for (int i = 0; i < NUM_MESSAGES; i++) {
        char value[10];
        sprintf(value, "%d", i);
        int priority = rand() % 256; // Генерация случайного приоритета от 0 до 255
        head = InsertSort(value, priority, head);
    }
    printf("\n Очередь перед удалением элементов:\n");
    printList(head);
    // Выбор случайного приоритета для удаления
    int delete_priority = rand() % 256;

    // Удаление элементов с приоритетом не ниже заданного
    for (int i = 0; i < NUM_MESSAGES; i++) {
    head = deleteValue(delete_priority, head);
    }
    printf("\n Очередь после удаления элементов с приоритетом не ниже %d:\n",delete_priority);
    printList(head);
    // Проверка, что все элементы с приоритетом не ниже заданного были удалены
    for (struct Item* item = head; item != NULL; item = item->next) {
        ck_assert_int_ge(item->priority, delete_priority);
    }

    // Очистка памяти
    deleteList(head);
}
END_TEST


Suite* queue_suite(void) {
    Suite* suite = suite_create("Queue add and delete");

    TCase* tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_insert_sort);
    tcase_add_test(tc_core, test_delete_value_priority);

    suite_add_tcase(suite, tc_core);

    return suite;
}

int main(void) {
    Suite* suite = queue_suite();
    SRunner* runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
