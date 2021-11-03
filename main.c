
/*#include <stdio.h>
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
*/

#include <stdio.h>
#include "NumClass.h"
int main(){
int a;
int b;
scanf("%d%d",&a,&b);
if(a<1){
    a=1;
}else if(b<1){
    b=1;
}
printf("The Armstrong numbers are:");
for(int i =a;i<=b;i++){
    if(isArmstrong(i)){
        printf(" %d",i);
    }
}
printf("\n");
    printf("The Palindromes are:");
for(int i =a;i<=b;i++){
    if(isPalindrome(i)){
        printf(" %d",i);
    }
}
printf("\n");
    printf("The Prime numbers are:");
for(int i =a;i<=b;i++){
    if(isPrime(i)){
        printf(" %d",i);
    }
}
printf("\n");
    printf("The Strong numbers are:");
for(int i =a;i<=b;i++){
    if(isStrong(i)){
        printf(" %d",i);
    }
}
printf("\n");
return 0;
}
