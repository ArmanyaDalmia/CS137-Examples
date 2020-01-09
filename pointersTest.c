#include <stdlib.h>

int main(void) {
  int *p = malloc(sizeof(int));
  int **p2 = malloc(sizeof(int*));
  void *p3; //can be casted as any data type
  //p2 = (int **)p;
  p = (int *) p2;
  p3 = p2;
  free(p);
  free(p2);
}