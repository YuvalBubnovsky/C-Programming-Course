#include <stdio.h>
#include "my_mat.h"

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

int has_path(int mat[N][N], int i, int j)
{
	if (mat[i][j] == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int get_weight(int mat[N][N], int i, int j)
{
	int flag = has_path(mat, i, j);
	if (flag == 0)
	{
		return 0;
	}
	else
	{
		return mat[i][j];
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
