/* Simple test for COREV reg-reg MEM extensions */

#define ARRAY_DIM 100
#define LOOP_DIM  20

signed char        char_array     [ARRAY_DIM];
signed short int   short_array    [ARRAY_DIM];
signed int         int_array      [ARRAY_DIM];
unsigned char      uns_char_array [ARRAY_DIM];
unsigned short int uns_short_array[ARRAY_DIM];
unsigned int       uns_int_array  [ARRAY_DIM];

int char_sum      = 0;
int short_sum     = 0;
int int_sum       = 0;
int uns_char_sum  = 0;
int uns_short_sum = 0;
int uns_int_sum   = 0;

void store_postdisp_inc()
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

void load_postdisp_inc()
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

void store_postdisp_dec()
{
  for(int i=0; i<LOOP_DIM; i++)
  {
    char_array     [(ARRAY_DIM-i)*5] = i;
    short_array    [(ARRAY_DIM-i)*5] = i;
    int_array      [(ARRAY_DIM-i)*5] = i;
    uns_char_array [(ARRAY_DIM-i)*5] = i;
    uns_short_array[(ARRAY_DIM-i)*5] = i;
    uns_int_array  [(ARRAY_DIM-i)*5] = i;
  }
}

void load_postdisp_dec()
{
  for(int i=0; i<LOOP_DIM; i++)
  {
    char_sum      += char_array     [(ARRAY_DIM-i)*5];
    short_sum     += short_array    [(ARRAY_DIM-i)*5];
    int_sum       += int_array      [(ARRAY_DIM-i)*5];
    uns_char_sum  += uns_char_array [(ARRAY_DIM-i)*5];
    uns_short_sum += uns_short_array[(ARRAY_DIM-i)*5];
    uns_int_sum   += uns_int_array  [(ARRAY_DIM-i)*5];
  }
}
