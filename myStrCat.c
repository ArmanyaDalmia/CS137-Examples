#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *myStrCat(const char *s0, const char *s1) {
  size_t s0len = strlen(s0);
  size_t s1len = strlen(s1);
  char *ret = malloc(sizeof(char)*(s0len + s1len +1));
  strcpy(ret, s0);
  strcat(ret, s1);
  return ret;
}

int main(void) {
  char s0[] = "What is 6x9?";
  char s1[] = " 42";
  char *s2 = myStrCat(s0, s1);
  printf("%s\n", s2);
  free(s2);
  printf("What is 6x9? 42\n");
}
