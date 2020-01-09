#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void *float_to_int(void *f) {
  float d = *(float*)f;
  int *i = malloc(sizeof(int));
  *i = (int)d;
  return i;
}

void *print_elen(void *f) {
  printf("%d\n", *(int*)f);
  int *ret = malloc(sizeof(int));
  *ret = *(int*)f;
  return ret;
}

void gen_map(void *src, size_t n, size_t srcb, void *dest, size_t destb, void *(*f) (void *)) {
  for (int i = 0; i < n; ++i) {

    void *ret = f(src);
    void *oldret = ret;
    for (int j = 0; j < destb; ++j) {
      *(char *)dest++ = *(char *)ret++;
    }
    src += srcb;

    free(oldret);
  }
}

void *float_to_int2(void *src, void *dest) {
  float d = *(float*)src;
  *(int*)dest = (int) d;
}

void print_int2(void *src, void *dest) {
  printf("%d ", *(int*)src);
}

void gen_array(void *src, void *dest) {
  int size;
}

void gen_map2(void *src, size_t n, size_t srcb, void *dest, size_t destb, void (*f) (void*,void*)) {

  for (int i = 0; i < n; ++i) {
    f(src, dest);
    src += srcb;
    dest +=destb;
  }

}

void main() {
  float a[] =  {4.5, 7.2, 90.0};
  int b[] = {0, 0 , 0};
  //gen_map(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), b, sizeof(b[0]), float_to_int);

  gen_map2(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), b, sizeof(b[0]), float_to_int2);
  gen_map2(b, sizeof(b)/sizeof(b[0]), sizeof(b[0]), b, sizeof(b[0]), print_int2);
  printf("\n");
  int sizes[] = {4, 2, 1};
  int *arrs[3] = {0};
  gen_map2(sizes, 3, sizeof(sizes[0]), arrs, sizeof(arrs[0]), gen_array);
}