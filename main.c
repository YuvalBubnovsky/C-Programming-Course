
#include <stdio.h>
#include "NumClass.h"

int main(){
  int start,end;
  scanf("%d%d",&start,&end);
  printf("The Armstrong numbers are: ");
  for(int i = start;i<=end;i++){
      if(isArmstrong(i) == 1){
          if(i == end){
            printf("%d",i);
          }
          printf("%d ",i);
    }
  }
  printf("\n");
  printf("The Palindromes are: ");
  for(int i = start;i<=end;i++){
      if(isPalindrome(i) == 1){
          if(i == end){
            printf("%d",i);
        }
          printf("%d ",i);
    }
  }
  printf("\n");
  printf("The Prime numbers are: ");
  for(int i = start;i<=end;i++){
      if(isPrime(i) == 1){
          if(i == end){
            printf("%d",i);
        }
          printf("%d ",i);
    }
  }
  printf("\n");
  printf("The Strong numbers are: ");
  for(int i = start;i<=end;i++){
      if(isPalindrome(i) == 1){
          if(i == end){
            printf("%d",i);
        }
          printf("%d ",i);
    }
  }
  return 0;
}
