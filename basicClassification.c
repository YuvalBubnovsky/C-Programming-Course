// Basic implementation of isPrime & isStrong functions

#include <stdio.h>
#include "NumClass.h"

int isPrime(int n) {
  for(int i = 2;i<=n/2;i++){
    if(n%i!=0){
      continue;
    } else {
      return 0;
    }
  }
  return 1;
}

int isStrong(int n) {
  int originalNum, lastDigit, sum, factorial;
  originalNum = n;
  sum = 0;
  while(n > 0 )
  {
      factorial = 1;
      lastDigit = n % 10;
      for(int i = 1;i<=lastDigit;i++){
          factorial *= i;
      }
      sum += factorial;
      n /= 10;
  }
  if(sum == originalNum){
    return 1;
  } else {
    return 0;
  }
}
