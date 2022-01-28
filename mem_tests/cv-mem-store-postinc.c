/* Simple test for COREV store post-increment MEM extensions */
/* { dg-do compile { target { riscv32-corev-elf } } } */
/* { dg-options "-march=rv32i_xcorevmem -O1" } */

#define ARRAY_DIM 100

signed char        char_array     [ARRAY_DIM] = {sizeof(signed char)};
signed short int   short_array    [ARRAY_DIM] = {sizeof(signed short int)};
signed int         int_array      [ARRAY_DIM] = {sizeof(signed int)};
unsigned char      uns_char_array [ARRAY_DIM] = {sizeof(unsigned char)};
unsigned short int uns_short_array[ARRAY_DIM] = {sizeof(unsigned short int)};
unsigned int       uns_int_array  [ARRAY_DIM] = {sizeof(unsigned int)};

void store_postinc()
{
  for(int i=0; i<ARRAY_DIM; i++)
  {
    char_array[i]      = 111-i;
    short_array[i]     = 23+i;
    int_array[i]       = 35+i;
    uns_char_array[i]  = 31+i;
    uns_short_array[i] = 12+i;
    uns_int_array[i]   = 4+i;
  }
}

/* { dg-final { scan-assembler-times "cv\.s" 6 } } */
/* { dg-final { scan-assembler-times "cv\.sb .\\d+, 1\\(.\\d+!\\)" 2 } } */
/* { dg-final { scan-assembler-times "cv\.sh .\\d+, 2\\(.\\d+!\\)" 2 } } */
/* { dg-final { scan-assembler-times "cv\.sw .\\d+, 4\\(.\\d+!\\)" 2 } } */