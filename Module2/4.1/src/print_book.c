#include "main.h"

// void print_book(struct contact *book, int pid) {
//   printf("PHOHE BOOK:\n");
//   for (int i = 0; i <= pid; i++) {
//     printf("id(%d)%s, %s\n",i, book.name.first_name, book.name.last_name);
//     if (*book.work.name == 0)
//       continue;
//     else {
//       printf("%s; ", book.work.name);
//       printf("%s; ", book.work.post);
//       printf("%s; ", book.phone_numbers.n1);
//       printf("%s; ", book.phone_numbers.n2);
//       printf("%s; ", book.email.e1);
//       printf("%s; ", book.email.e2);
//       printf("%s; ", book.links.l1);
//       printf("%s; \n", book.links.l2);
//     }
//   }
// }

void clear() { printf("\033[0d\033[2J"); }