#ifndef CONTACT_H
#define CONTACT_H

#define SIZE_STR 20

typedef struct {
  char first_name[SIZE_STR];
  char last_name[SIZE_STR];
} name;

typedef struct {
  char name[SIZE_STR];
  char post[SIZE_STR];
} work;

typedef struct {
  char n1[SIZE_STR];
  char n2[SIZE_STR];
} phone_numbers;

typedef struct {
  char e1[SIZE_STR];
  char e2[SIZE_STR];
} email;


typedef struct {
  char l1[SIZE_STR];
  char l2[SIZE_STR];
} links;

#endif //CONTACT_H