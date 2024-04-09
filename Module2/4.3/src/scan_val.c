#include "main.h"

void scan_val(struct contact* newItem){
    clear();
  printf("Write first name\n");
  scanf("%s", newItem->name.first_name);
  printf("Write last name\n");
  scanf("%s", newItem->name.last_name);
  printf("Do you want to continue?\n");
  printf("1-YES\n");
  printf("0-NO\n");
  int choice = 0;
  scanf("%d", &choice);
  if (choice == 1) {
    printf("Write work name\n");
    scanf("%s", newItem->work.name);
    printf("Write work post\n");
    scanf("%s", newItem->work.post);

    printf("Write phone number 1\n");
    scanf("%s", newItem->phone_numbers.n1);
    printf("Write phone number 2\n");
    scanf("%s", newItem->phone_numbers.n2);

    printf("Write email 1\n");
    scanf("%s", newItem->email.e1);
    printf("Write email 2\n");
    scanf("%s", newItem->email.e2);

    printf("Write link 1\n");
    scanf("%s", newItem->links.l1);
    printf("Write link 2\n");
    scanf("%s", newItem->links.l2);
}
}

void clear() { printf("\033[0d\033[2J"); }