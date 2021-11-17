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
      for (int k = 0; i < N; i++)
      {
        for (int p = 0; j < N; j++)
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
