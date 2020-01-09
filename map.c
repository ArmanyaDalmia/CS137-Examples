#include <stdio.h>

void map(int *a, size_t n, int *b, int (*f)(int)) {
  for (int i = 0; i < n; ++i) {
    *b++ = f(*a++);
  }
}

int mult_by_two(int n) { return n*2; }

int print_elen (int n) {
  printf("%d\n", n);
  return n;
}

int fib(int n) {
  int prev = 0;
  int cur = 1;
  for (int i = 2; i<= n; ++i) {
    int temp = cur;
    cur += prev;
    prev = temp;
  }
  return cur;
}

int main() {
  int a[]= {5, 4, 3, 2, 1};
  int b[]= {0, 0, 0, 0, 0};
  map(a, sizeof(a)/sizeof(a[0]), b, mult_by_two);
  map(b, sizeof(b)/sizeof(b[0]), b, print_elen);
  printf("\n");
  map(a, sizeof(a)/sizeof(a[0]), b, fib);
  map(b, sizeof(b)/sizeof(b[0]), b, print_elen);


}