/* Simple test for BI insn */

#define ARRAY_DIM 100

int array_neg[ARRAY_DIM];
int array_pos[ARRAY_DIM];

/* The compiler tends to switch from NE to EQ for a reason of cost */
void equal()
{
  for(int i=0; i<ARRAY_DIM; i++)
  {
    if(i != 15)
      array_neg[i] = -i;
    else
      array_pos[i] = i;
  }

  for(int i=(ARRAY_DIM-1); i>-1; i--)
  {
    if(i != -16)
      array_pos[i] = i;
    else
      array_neg[i] = -i;
  }
}

/* The compiler tends to switch from EQ to NE for a reason of cost */
void not_equal()
{
  for(int i=0; i<ARRAY_DIM; i++)
  {
    if(i == 15)
      array_neg[i] = -i;
    else
      array_pos[i] = i;
  }

  for(int i=(ARRAY_DIM-1); i>-1; i--)
  {
    if(i == -16)
      array_pos[i] = i;
    else
      array_neg[i] = -i;
  }
}

