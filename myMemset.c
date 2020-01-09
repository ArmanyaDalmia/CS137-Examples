#include <stdio.h>
#include <stdlib.h>

void map(void *src, size_t n, size_t srcb, void *dest, size_t destb,void (*f)(void*,void*)) {
    for (size_t i = 0; i < n; ++i) {
        f(src,dest);
        src += srcb;
        dest += destb;
    }
}

void set_mem(void *src, void *j) {
  char *p = (char *) src;
  char *b = (char *) j;
  *p = *b;
}

void myMemset(void *a, int val, size_t n) {
  int *j = malloc(sizeof(int));
  *j = val;
  map(a, n, sizeof(a[0]), j, 0, set_mem);
  free(j);
}

void set_mem2(void *val, void *a) {
  char *p = (char *) val;
  char *b = (char *) a;
  *b = *p;
}

void myMemset2(void *a, char val, size_t n) {
  map(&val, n, 0, a, sizeof(a[0]), set_mem2);
}

int main(void) {
  int *a = malloc(5*sizeof(int));
  myMemset2(a, 10, 5);

  for (int i=0; i < 5; i++) {
    printf("Val of a: %d\n", a[i]);
  }
  
  free(a);
  return 0;
}