/* Simple test for COREV standard pattern MEM extensions */

#define ARRAY_DIM 100

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

void load_postdec()
{
  for(int i=0; i<ARRAY_DIM; i++)
  {
    char_sum      += char_array[ARRAY_DIM-i];
    short_sum     += short_array[ARRAY_DIM-i];
    int_sum       += int_array[ARRAY_DIM-i];
    uns_char_sum  += uns_char_array[ARRAY_DIM-i];
    uns_short_sum += uns_short_array[ARRAY_DIM-i];
    uns_int_sum   += uns_int_array[ARRAY_DIM-i];
  }
}

