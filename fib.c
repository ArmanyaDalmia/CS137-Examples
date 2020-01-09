#include <stdio.h>

int fib(int n) {
  if (n==0) {
    return 0;
  }
  if (n==1) {
    return 1;
  }
  return fib(n-1)+fib(n-2);
}

int main() {
  printf("%d\n", fib(3));
  printf("%d\n", fib(10));
  //fib(45)is the largest number that can fit in an int
  //very slow because is O(2^n), each fib call splits into 2
  printf("%d\n", fib(45));
  return 0;
}