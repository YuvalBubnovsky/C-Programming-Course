#include <stdio.h>
#include "my_mat.h"

#define N 10

int mat[N][N];
int min(int, int, int);

void floyd(int mat[N][N]) // Floyd-Warshall algorithm implementation in C
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
					// This is where the magic happens - using a custom min function,
					// we make sure that the path value isn't nullifed incase the regualr
					// min valute is 0 and in case either mat[i][k] or mat[k][j] is equal to 0
					mat[i][j] = min(mat[i][j], mat[i][k], mat[k][j]);
				}
			}
		}
	}
}

// Returns true if a path exists on the graph
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

// Returns the weight of the shortest path on the graph
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

// Custom min function to account for edge-cases in the Floyd-Warshall algorithm
int min(int a, int b, int c)
{
	if (b != 0 && c != 0 && b + c < a)
	{
		return (b + c);
	}
	else
	{
		return (a);
	}
}
