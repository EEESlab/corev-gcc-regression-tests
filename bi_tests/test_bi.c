/* Simple test for BI insn */

#define ARRAY_DIM 15

int main();

int array[ARRAY_DIM];

int main()
{
  for(int i=0; i<ARRAY_DIM; i++)
  {
    array[i] = i-ARRAY_DIM;
  }

  for(int i=0; i<ARRAY_DIM; i++)
  {
    if(array[i] == -1)
      break;
    else
      array[i] = i;
  }

  return 0;
}

