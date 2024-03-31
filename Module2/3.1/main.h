#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> 
#include <string.h>

void mask();
void print_bits(int a);
int number_mask(char* mask);
int letter_mask(char* u, int* a, int num);
void set_bit(int *number, int pos_bit, short bit);
int get_bit(int bit, int pos_bit);

#endif // MAIN_H