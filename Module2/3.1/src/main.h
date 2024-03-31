#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> 
#include <string.h>
#include <sys/stat.h>

int mask();
int number_mask(char* mask);
int letter_mask(char* u, int* a, int num);

void set_bit(int *number, int pos_bit, short bit);
int get_bit(int bit, int pos_bit);

void option_action(int opt,int* result);
void menu(int *option,int* result);

int file_mask();
int get_file_permissions(const char *filename);

void change_rights(int res);
int pars_user(char* param,int* minus);
void create_mask(char* param, char user, int* main_mask,int *minus);
// void pars_access(char* param, char user, int* main_mask,int* minus);
// void set_mask_bit(char* param, int minus, int* mask);
// void set_main_mask_bit(char user,int mask,int minus, int* main_mask);

void print_bits(int a);
void print_numbers(int a);
void print_bykva(int a);


#endif // MAIN_H