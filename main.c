#include <stdio.h>
#include "my_mat.h"

#define N 10

int mat[N][N];
int i, j;

int main(void)
{
  int flag = 1;

  while (flag == 1)
  {
    char input = getchar();
    switch (input)
    {
    case 'A': // Input a matrix
              // We are resetting the matrix's value to 0 incase this is not the first matrix since the program started
      for (int k = 0; k < N; k++)
      {
        for (int p = 0; p < N; p++)
        {
          mat[k][p] = 0;
        }
      }
      // This is the actual input of the matrix
      for (int k = 0; k < N; k++)
      {
        for (int p = 0; p < N; p++)
        {
          scanf("%d", &mat[k][p]);
        }
      }
      floyd(mat);
      break;

    case 'B': // Check if a path exists
      scanf("%d%d", &i, &j);
      if (has_path(mat, i, j) == 1)
      {
        printf("True");
        printf("\n");
      }
      else
      {
        printf("False");
        printf("\n");
      }
      break;

    case 'C': // Return the weight of the shortest path
      scanf("%d%d", &i, &j);
      if (has_path(mat, i, j) == 1)
      {
        printf("%d", mat[i][j]);
        printf("\n");
      }
      else
      {
        printf("-1");
        printf("\n");
      }
      break;

    case 'D': // Exit the program
      flag = 0;
    }
  }
  return 0;
}
