#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

typedef struct {
  char first_name[20];
  char last_name[20];
} name;

typedef struct {
  char name[20];
  char post[20];
} work;

typedef struct {
  char n1[20];
  char n2[20];
} phone_numbers;

typedef struct {
  char l1[20];
  char l2[20];
} links;

typedef struct {
  int id;
  name name;
  work work;
  phone_numbers phone_numbers;
  char email[20];
  links links;
} contact;

void clear();
void menu(int *option, contact *book, int *person_id);
void option_action(const int opt, contact *book, int *person_id);
void add(contact *book, int *pid);
void edit(contact *book, int pid);
void delete (contact *book, int person_id);
void print_book(contact *book, int pid);

#endif // MAIN_H