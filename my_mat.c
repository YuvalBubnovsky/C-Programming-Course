#include <stdio.h>
#include "my_mat.h"

#define N 10

int mat[N][N];
int min(int, int);

// This function recieves adjacency-matrix as user input and runs the Floyd-Warshall algorithm on it
void get_matrix(int mat[N][N])
{
	for (int k = 0; k < N; k++)
	{
		for (int p = 0; p < N; p++)
		{
			scanf("%d", &mat[k][p]);
		}
	}
	floyd(mat);
}

void floyd(int mat[N][N]) // Floyd-Warshall algorithm implementation in C
{
	int i, j, k;
	for (k = 0; k < N; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (mat[i][j] != 0 && mat[i][k] != 0 && mat[k][j] != 0)
				{
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
				if (i != j && mat[i][j] == 0 && mat[i][k] != 0 && mat[k][j] != 0)
				{
					mat[i][j] = mat[i][k] + mat[k][j];
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
