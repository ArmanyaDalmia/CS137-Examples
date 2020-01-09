#include <stdio.h>

struct l1{
  struct l1node *head;
};

struct l1node{
  int item;
  struct l1node *next;
};

int main(void) {
  printf("Hello World\n");
  return 0;
}