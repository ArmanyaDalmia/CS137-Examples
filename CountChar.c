#include <stdio.h>

// Takes s, a pointer to a STRING, so we are gaurenteed it should "end" at the first null character
int countChar2(char *s, char c) {
  int count = 0;
  // could also have stopping condition be s[i] = 0;
  // or just s[i]
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == c) ++count;
  }
  return count;
}

// Same program except using recursion
int countChar(char *s, char c) {
  return *s ? (*s == c) + countChar(s+1, c) : 0;
}
 
int main() {
  char s[] = "Fortnite and helping my parents shovel the snow";
  printf("The number of e's in \"%s\" is %d\n", s, countChar(s, 'e'));
}