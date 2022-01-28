/* Test for COREV MEM extensions with nested loops */
/* { dg-do compile { target { riscv32-corev-elf } } } */
/* { dg-options "-march=rv32i_xcorevmem -O1" } */

#define N_ROW_A 10
#define N_COL_A 10
#define N_ROW_B 10
#define N_COL_B 10

#define MATRIX_A_DIM N_ROW_A*N_COL_A
#define MATRIX_B_DIM N_COL_B*N_ROW_B
#define MATRIX_C_DIM N_ROW_A*N_COL_B

int matrix_a[MATRIX_A_DIM] = {1};
int matrix_b[MATRIX_B_DIM] = {1};
int matrix_c[MATRIX_C_DIM] = {0};

int partial_sum = 0;

void matmul()
{
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

/* { dg-final { scan-assembler-times "cv\.sw .\\d+, 4\\(.\\d+!\\)" 1 } } */
/* { dg-final { scan-assembler-times "cv\.lw .\\d+, \\d+\\(.\\d+!\\)" 2 } } */