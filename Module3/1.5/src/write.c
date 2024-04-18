#include "lib_src/main.h"

void write_list(struct contact* head) {

int fd;
fd = open("contact_list",O_CREAT||O_APPEND);

struct contact* tmp = head;
if (NULL == head) {
printf("List empty!\n");
return;
}
do {
write(fd,head,sizeof(head));
tmp = tmp->next;
} while (tmp != head);
close(fd);
}