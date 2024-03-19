#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[30];
    char work[20];
    char phone_numbers[50];
    char email[20];
    char links[100];
}contact;

void clear();
void menu(int* option, contact* book, int* person_id );
void option_action(const int opt, contact* book, int* person_id);
void add(contact* book,int* pid);
void edit(contact* book,int pid);
void delete(contact* book,int person_id);




#endif // MAIN_H