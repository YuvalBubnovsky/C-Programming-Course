
#include <stdio.h>
#include "NumClass.h"

int main(){
  int start;
  int end;
  scanf("%d%d",&start,&end);
  if(start<1){
      start=1;
    }else if(end<1){
      end=1;
}
printf("The Armstrong numbers are:");
for(int i=start;i<=end;i++){
    if(isArmstrong(i)){
        printf(" %d",i);
    }
}
printf("\n");
    printf("The Palindromes are:");
for(int i=start;i<=end;i++){
    if(isPalindrome(i)){
        printf(" %d",i);
    }
}
printf("\n");
    printf("The Prime numbers are:");
for(int i=start;i<=end;i++){
    if(isPrime(i)){
        printf(" %d",i);
    }
}
printf("\n");
    printf("The Strong numbers are:");
for(int i=start;i<=end;i++){
    if(isStrong(i)){
        printf(" %d",i);
    }
}
printf("\n");
return 0;
}
