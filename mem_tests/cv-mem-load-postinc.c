/* Simple test for COREV load post-increment MEM extensions */
/* { dg-do compile { target { riscv32-corev-elf } } } */
/* { dg-options "-march=rv32i_xcorevmem -O1" } */

#define ARRAY_DIM 100

signed char        char_array     [ARRAY_DIM] = {sizeof(signed char)};
signed short int   short_array    [ARRAY_DIM] = {sizeof(signed short int)};
signed int         int_array      [ARRAY_DIM] = {sizeof(signed int)};
unsigned char      uns_char_array [ARRAY_DIM] = {sizeof(unsigned char)};
unsigned short int uns_short_array[ARRAY_DIM] = {sizeof(unsigned short int)};
unsigned int       uns_int_array  [ARRAY_DIM] = {sizeof(unsigned int)};

int char_sum      = 0;
int short_sum     = 0;
int int_sum       = 0;
int uns_char_sum  = 0;
int uns_short_sum = 0;
int uns_int_sum   = 0;

void load_postinc()
{
  for(int i=0; i<ARRAY_DIM; i++)
  {
    char_sum      += char_array[i];
    short_sum     += short_array[i];
    int_sum       += int_array[i];
    uns_char_sum  += uns_char_array[i];
    uns_short_sum += uns_short_array[i];
    uns_int_sum   += uns_int_array[i];
  }
}

/* { dg-final { scan-assembler-times "cv\.l" 6 } } */
/* { dg-final { scan-assembler-times "cv\.lb .\\d+, 1\\(.\\d+!\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lbu .\\d+, 1\\(.\\d+!\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lh .\\d+, 2\\(.\\d+!\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lhu .\\d+, 2\\(.\\d+!\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lw .\\d+, 4\\(.\\d+!\\)" 2 } } */