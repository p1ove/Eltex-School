#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

struct contact {
  int id;
  struct contact* next;
  struct contact* prev;

  name name;
  work work;
  phone_numbers phone_numbers;
  email email;
  links links;
};

void clear();
void menu(int *option, struct contact *book, int *person_id);
void option_action(const int opt, struct contact *book, int *person_id);
void add(struct contact *book, int *pid);
void edit(struct contact *book, int pid);
void delete (struct contact *book, int person_id);
void scan_val(struct contact* newItem);
// void print_book(struct contact *book, int pid);

struct contact* InsertValue(int val, struct contact* head);
struct contact* DeleteValue(int val, struct contact* head);
struct contact* DeleteList(struct contact* head);
void PrintList(struct contact* head);

#endif // MAIN_H