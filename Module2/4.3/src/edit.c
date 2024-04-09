// #include "main.h"

// void edit(struct contact *book, int pid) {
//   char name[30];
//   int err = 1;
//   while (err) {
//     clear();
//     print_book(book, pid);
//     if (err == 2) {
//       printf("Incorrect person first name\n");
//     }
//     printf("Write person first name\n");
//     scanf("%s", name);
//     for (int i = 0; i <= pid; i++) {
//       if (strcmp(name, book[i].name.first_name) != 0) {
//       } else {
//         err = 0;
//         add(book, &i);
//         break;
//       }
//       err = 2;
//     }
//   }
// }