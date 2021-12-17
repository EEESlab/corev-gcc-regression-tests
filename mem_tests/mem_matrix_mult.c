/* Test for COREV MEM extensions with nested loops */

#define N_ROW_A 10
#define N_COL_A 10
#define N_ROW_B 10
#define N_COL_B 10

#define MATRIX_A_DIM N_ROW_A*N_COL_A
#define MATRIX_B_DIM N_COL_B*N_ROW_B
#define MATRIX_C_DIM N_ROW_A*N_COL_B

/* A x B = C : [N_ROW_AxN_COL_A] x [N_ROW_BxN_COL_B] = [N_ROW_AxN_COL_B] */
int matrix_a[MATRIX_A_DIM];
int matrix_b[MATRIX_B_DIM];
int matrix_c[MATRIX_C_DIM];

int partial_sum = 0;

void matmul()
{
  /* INIT */
  /* Columns first */
  /* three stores with standard pattern post-incrementing */
  for(int i=0; i<N_ROW_A*N_COL_A; i++)
  {
    matrix_a[i] = 0x1;
  }

  for(int i=0; i<N_ROW_B*N_COL_B; i++)
  {
    matrix_b[i] = 0x1;
  }

  for(int i=0; i<N_ROW_A*N_COL_B; i++)
  {
    matrix_c[i] = 0x0;   
  }

  /* COMPUTE */
  for(int j=0; j<N_ROW_A; j++)
  {
    for(int i=0; i<N_COL_B; i++)
    {
      /* two loads with indexed post-incrementing */
      for(int k=0; k<N_COL_A; k++)
      {
        partial_sum += matrix_a[k + j*N_COL_A] * matrix_b[k*N_COL_B + i];
      }
      /* one store with indexed post-incrementing */
      matrix_c[i + j*N_COL_B] = partial_sum;
    }
  }
}

