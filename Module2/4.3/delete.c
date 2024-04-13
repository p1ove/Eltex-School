#include "main.h"

void delete (struct contact *book, int pid) {
  int id = 0;
  int err = 1;
  while (err) {
    clear();
    PrintList(book);
    if (err == 2) {
      printf("Incorrect person id\n");
    }
    printf("Write person id\n");
    scanf("%d", &id);
    if(id<=pid){
       Delete(id,&book);
       break;
    }
    err = 2;
  }
}