#include <stdio.h>
#include "vector.c"

void reduce(void *src, size_t n, size_t srcb, void *dest, void (*f)(void*, void*, void*)) {
  if (n==1) {
    f(src, dest, dest);
    return;
  }
  reduce(src + srcb, n-1, srcb, dest, f);
  f(src, dest, dest);

}

void mult(void *lhs, void *rhs, void *dest) {
  int l = *(int*)lhs;
  int r = *(int*)rhs;
  int *d = dest;
  *d = l*r;
}

void dest_sort(void *num, void *vec, void *dest) {
  struct vector *v = vec;
  int n = *(int *)num;
  if (vectorLength(v) == 0) {
    vectorAdd(v, *(int*)num);
    return;
  }
  int firstElem = vectorGet(v, 0);
  if (firstElem < n) {
    return;
  }
  vectorAdd(v, 0);
  for (int i=vectorLength(v) -1; i >= 1; --i) {
    vectorSet(v, i, vectorGet(v, i - 1));
  }
  vectorSet(v,0,n);
}

int main(void) {
  int a[] = {5, 4, 3, 2, 1};
  int answer = 1;
  reduce(a, 5, sizeof(int), &answer, mult);
  printf("%d \n", answer);

  // Based on vector.c
  struct vector*c = vectorCreate();
  int b[] = {7, 15, -5, 8, 20, 13};
  reduce(b, 6, sizeof(int), v, dest_sort);

}