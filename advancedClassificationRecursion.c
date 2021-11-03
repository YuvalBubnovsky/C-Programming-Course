// Implementation of isArmstrong & isPalindrome using recursion

#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int reversedNum(int n);
int armHelper(int n);

int reversedNum(int n){
  if(n == 0){
      return 0;
  }
  int numOfDigits = (int)log10(n) + 1;
  return ((n%10 * pow(10,numOfDigits)) + reversedNum(n/10));
}

int isPalindrome(int n){
  if(n == reversedNum(n)){
      return 1;
  } else {
      return 0;
  }
}

int armHelper(int n){
    int numOfDigits = (int)log10(n) + 1;
    return(pow(n%10,numOfDigits) + armHelper(n/10));
}

int isArmstrong(int n){
    if(n == armHelper(n)){
      return 1;
    } else {
      return 0;
    }
}
