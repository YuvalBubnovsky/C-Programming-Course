#include<stdio.h>
#include<conio.h>

#define N 10

int min(int,int);

void get_matrix(){
	for(int i = 0;i < N; i++){
		for(int j = 0;j < N; j++){
			scanf("%d", &mat[i][j]);
		}
	}
}

void floyd(int mat[N][N],int n) {
	int i,j,k;
	for (k=1;k<=n;k++){
			for (i=1;i<=n;i++){
	   		for (j=1;j<=n;j++){
	    		if(i==j){
	     			mat[i][j]=0;
     		} else {
	     			mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
        }
      }
    }
  }
}

int min(int a,int b) {
	if(a<b){
	  return(a);
  } else {
	  return(b);
    }
  }
