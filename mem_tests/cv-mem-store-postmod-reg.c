/* Simple test for COREV store post-modify register MEM extensions */
/* { dg-do compile { target { riscv32-corev-elf } } } */
/* { dg-options "-march=rv32i_xcorevmem -O1" } */

#define ARRAY_DIM 8192

signed char        char_array     [ARRAY_DIM] = {sizeof(signed char)};
signed short int   short_array    [ARRAY_DIM] = {sizeof(signed short int)};
signed int         int_array      [ARRAY_DIM] = {sizeof(signed int)};
unsigned char      uns_char_array [ARRAY_DIM] = {sizeof(unsigned char)};
unsigned short int uns_short_array[ARRAY_DIM] = {sizeof(unsigned short int)};
unsigned int       uns_int_array  [ARRAY_DIM] = {sizeof(unsigned int)};

void store_reg_reg()
{
  char_array     [4096] = 132;
  short_array    [4096] = -4;
  int_array      [4096] = 35;
  uns_char_array [4096] = 99;
  uns_short_array[4096] = 12;
  uns_int_array  [4096] = 33;
}

/* { dg-final { scan-assembler-times "cv\.s" 6 } } */
/* { dg-final { scan-assembler-times "cv\.sb .\\d+, .\\d+\\(.\\d+\\)" 2 } } */
/* { dg-final { scan-assembler-times "cv\.sh .\\d+, .\\d+\\(.\\d+\\)" 2 } } */
/* { dg-final { scan-assembler-times "cv\.sw .\\d+, .\\d+\\(.\\d+\\)" 2 } } */