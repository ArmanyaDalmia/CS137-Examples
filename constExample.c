#include <stdio.h>

int main(void) {
  int x = 5;
  int y = 20;
  int const *p1 = &x; // Pointer 
  const int *p2 = &x;
  int *const p3 = &x;
  *p1 = 10;
  p1 = &y;
  *p3 = 20;
  p3 = &y;
}