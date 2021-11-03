// Implementation of isArmstrong & isPalindrome using recursion

#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int reversedNum(int n);
int armHelper(int n, int digits);

int paliHelper(char A[],int i,int j){
 if(i==j||(i==j-1&&A[i]==A[j])){
     return 1;
 }else if(A[j]!=A[i]){
     return 0;
 }else{
     return paliHelper(A,++i,--j);
 }
}
int isPalindrome(int a){
if(a<0){
	return 0;
}
   int length=(int)log10((double)a)+1;
   char A[length];
   sprintf(A,"%d",a);
   int n = sizeof(A) / sizeof(char);
    return paliHelper(A,0,n-1);
  }

int armHelper(int n,int digits){
  if(n==0){
    return 0;
  }
  int size = (int)log10(n) + 1;
  if(size == 1){
    return pow(n,digits);
  } else {
    return(pow(n%10,digits) + armHelper(n/10,digits));
  }
}

int isArmstrong(int n){
    int numOfDigits = (int)log10(n) + 1;
    if(n == armHelper(n,numOfDigits)){
      return 1;
    } else {
      return 0;
    }
}
