/* Simple test for COREV store post-modify displacement with increment MEM extensions */
/* { dg-do compile { target { riscv32-corev-elf } } } */
/* { dg-options "-march=rv32i_xcorevmem -O1" } */

#define ARRAY_DIM 100
#define LOOP_DIM  20

signed char        char_array     [ARRAY_DIM] = {sizeof(signed char)};
signed short int   short_array    [ARRAY_DIM] = {sizeof(signed short int)};
signed int         int_array      [ARRAY_DIM] = {sizeof(signed int)};
unsigned char      uns_char_array [ARRAY_DIM] = {sizeof(unsigned char)};
unsigned short int uns_short_array[ARRAY_DIM] = {sizeof(unsigned short int)};
unsigned int       uns_int_array  [ARRAY_DIM] = {sizeof(unsigned int)};

void store_postmod_disp_inc()
{
  for(int i=0; i<LOOP_DIM; i++)
  {
    char_array     [i*5] = i;
    short_array    [i*5] = i;
    int_array      [i*5] = i;
    uns_char_array [i*5] = i;
    uns_short_array[i*5] = i;
    uns_int_array  [i*5] = i;
  }
}

/* { dg-final { scan-assembler-times "cv\.s" 6 } } */
/* { dg-final { scan-assembler-times "cv\.sb .\\d+, 5\\(.\\d+!\\)" 2 } } */
/* { dg-final { scan-assembler-times "cv\.sh .\\d+, 10\\(.\\d+!\\)" 2 } } */
/* { dg-final { scan-assembler-times "cv\.sw .\\d+, 20\\(.\\d+!\\)" 2 } } */