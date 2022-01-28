/* Simple test for COREV load post-modify displacement with increment MEM extensions */
/* { dg-do compile { target { riscv32-corev-elf } } } */
/* { dg-options "-march=rv32i_xcorevmem -O1" } */

#define ARRAY_DIM 100
#define LOOP_DIM  20

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

void load_postmod_disp_inc()
{
  for(int i=0; i<LOOP_DIM; i++)
  {
    char_sum      += char_array     [i*5];
    short_sum     += short_array    [i*5];
    int_sum       += int_array      [i*5];
    uns_char_sum  += uns_char_array [i*5];
    uns_short_sum += uns_short_array[i*5];
    uns_int_sum   += uns_int_array  [i*5];
  }
}

/* { dg-final { scan-assembler-times "cv\.l" 6 } } */
/* { dg-final { scan-assembler-times "cv\.lb .\\d+, 5\\(.\\d+!\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lbu .\\d+, 5\\(.\\d+!\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lh .\\d+, 10\\(.\\d+!\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lhu .\\d+, 10\\(.\\d+!\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lw .\\d+, 20\\(.\\d+!\\)" 2 } } */