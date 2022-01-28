/* Simple test for COREV store post-decrement MEM extensions */
/* { dg-do compile { target { riscv32-corev-elf } } } */
/* { dg-options "-march=rv32i_xcorevmem -O1" } */

#define ARRAY_DIM 100

signed char        char_array     [ARRAY_DIM] = {sizeof(signed char)};
signed short int   short_array    [ARRAY_DIM] = {sizeof(signed short int)};
signed int         int_array      [ARRAY_DIM] = {sizeof(signed int)};
unsigned char      uns_char_array [ARRAY_DIM] = {sizeof(unsigned char)};
unsigned short int uns_short_array[ARRAY_DIM] = {sizeof(unsigned short int)};
unsigned int       uns_int_array  [ARRAY_DIM] = {sizeof(unsigned int)};

void store_postdec()
{
  for(int i=0; i<ARRAY_DIM; i++)
  {
    char_array[ARRAY_DIM-i]      = 33+i;
    short_array[ARRAY_DIM-i]     = -123-i;
    int_array[ARRAY_DIM-i]       = 53-i;
    uns_char_array[ARRAY_DIM-i]  = 6+i;
    uns_short_array[ARRAY_DIM-i] = 9+i;
    uns_int_array[ARRAY_DIM-i]   = 71+i;
  }
}

/* { dg-final { scan-assembler-times "cv\.s" 6 } } */
/* { dg-final { scan-assembler-times "cv\.sb .\\d+, -1\\(.\\d+!\\)" 2 } } */
/* { dg-final { scan-assembler-times "cv\.sh .\\d+, -2\\(.\\d+!\\)" 2 } } */
/* { dg-final { scan-assembler-times "cv\.sw .\\d+, -4\\(.\\d+!\\)" 2 } } */