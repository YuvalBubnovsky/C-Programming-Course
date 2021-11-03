// Implementation of isArmstrong & isPalindrome using loops

#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int n){
  int reversedNum, remainder, originalNum;
  reversedNum = 0;
  originalNum = n;
  while(n!=0)
  {
      remainder = n % 10;
      reversedNum = reversedNum * 10 + remainder;
      n /= 10;
  }
    if(reversedNum == originalNum)
  {
      return 1;
  } else {
      return 0;
  }
}


int isArmstrong(int n){
  int originalNum, sum, lastDigit;
  double numOfDigits = 0;
  sum = 0;
  originalNum = n;
  while(n!=0){
      n = n/10;
      numOfDigits++;
  }
  n = originalNum;
  for(int i = 1;i<=numOfDigits;i++){
      lastDigit = n % 10;
      double temp = pow(lastDigit,numOfDigits);
      sum += temp;
      n /= 10;
  }
  if(sum == originalNum){
      return 1;
  } else {
      return 0;
  }
}
