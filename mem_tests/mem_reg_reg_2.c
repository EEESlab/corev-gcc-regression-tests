/* Simple test for COREV reg-reg MEM extensions */

#define ARRAY_DIM 8192

volatile signed char        char_array     [ARRAY_DIM];
volatile signed short int   short_array    [ARRAY_DIM];
volatile signed int         int_array      [ARRAY_DIM];
volatile unsigned char      uns_char_array [ARRAY_DIM];
volatile unsigned short int uns_short_array[ARRAY_DIM];
volatile unsigned int       uns_int_array  [ARRAY_DIM];

volatile int char_sum      = 0;
volatile int short_sum     = 0;
volatile int int_sum       = 0;
volatile int uns_char_sum  = 0;
volatile int uns_short_sum = 0;
volatile int uns_int_sum   = 0;

int indexing[6] = {sizeof(char), sizeof(short int), sizeof(int), sizeof(unsigned char), sizeof(unsigned short int), sizeof(unsigned int)};

void store_reg_reg()
{
  char_array     [4096] = 132;
  short_array    [4096] = -4;
  int_array      [4096] = 35;
  uns_char_array [4096] = 99;
  uns_short_array[4096] = 12;
  uns_int_array  [4096] = 33;
}

void load_reg_reg()
{
  char_sum      += char_array     [4096];
  short_sum     += short_array    [4096];
  int_sum       += int_array      [4096];
  uns_char_sum  += uns_char_array [4096];
  uns_short_sum += uns_short_array[4096];
  uns_int_sum   += uns_int_array  [4096];
}

