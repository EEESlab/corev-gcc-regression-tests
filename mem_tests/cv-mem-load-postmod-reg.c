/* Simple test for COREV load post-modify register MEM extensions */
/* { dg-do compile { target { riscv32-corev-elf } } } */
/* { dg-options "-march=rv32i_xcorevmem -O1" } */

#define ARRAY_DIM 8192

signed char        char_array     [ARRAY_DIM] = {sizeof(signed char)};
signed short int   short_array    [ARRAY_DIM] = {sizeof(signed char)};
signed int         int_array      [ARRAY_DIM] = {sizeof(signed char)};
unsigned char      uns_char_array [ARRAY_DIM] = {sizeof(signed char)};
unsigned short int uns_short_array[ARRAY_DIM] = {sizeof(signed char)};
unsigned int       uns_int_array  [ARRAY_DIM] = {sizeof(signed char)};

int char_sum      = 0;
int short_sum     = 0;
int int_sum       = 0;
int uns_char_sum  = 0;
int uns_short_sum = 0;
int uns_int_sum   = 0;

void load_reg_reg()
{
  char_sum      += char_array     [4096];
  short_sum     += short_array    [4096];
  int_sum       += int_array      [4096];
  uns_char_sum  += uns_char_array [4096];
  uns_short_sum += uns_short_array[4096];
  uns_int_sum   += uns_int_array  [4096];
}

/* { dg-final { scan-assembler-times "cv\.l" 6 } } */
/* { dg-final { scan-assembler-times "cv\.lb .\\d+, .\\d+\\(.\\d+\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lbu .\\d+, .\\d+\\(.\\d+\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lh .\\d+, .\\d+\\(.\\d+\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lhu .\\d+, .\\d+\\(.\\d+\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lw .\\d+, .\\d+\\(.\\d+\\)" 2 } } */