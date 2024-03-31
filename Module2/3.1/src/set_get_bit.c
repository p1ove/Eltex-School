#include "main.h"

void set_bit(int *number, int pos_bit, short bit) {
  int bits_32[32] = {0};
  for (int i = 0; i < 32; i++) {
    bits_32[i] = 1 << i;
  }
  if (bit)
    *number |= bits_32[pos_bit - 1];
  else
    *number &= ~bits_32[pos_bit - 1];
}

int get_bit(int bit, int pos_bit) {
  return (bit >> (--pos_bit)) & 1;
}