#include <stdio.h>

#define N 10

void get_matrix(int mat[N][N]);
void floyd();
int has_path(int mat[N][N], int i, int j);
int get_weight(int mat[N][N], int i, int j);
int min(int a, int b);