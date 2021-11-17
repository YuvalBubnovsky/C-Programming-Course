#include <stdio.h>

#define N 10

int mat[N][N];
int min(int, int);

void get_matrix()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	floyd(mat[N][N]);
}

void floyd(int mat[N][N])
{
	int i, j, k;
	for (k = 0; k < N; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (i == j)
				{
					mat[i][j] = 0;
				}
				else
				{
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}
	}
}

int min(int a, int b)
{
	if (a < b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}
