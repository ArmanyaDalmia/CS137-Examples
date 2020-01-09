#include <stdio.h>
#include <stdlib.h>

typedef struct llnode {
  void * data;
  struct llnode *next;
} llnode;

typedef struct ll {
  llnode *head;
}ll;

ll *llcreate() {
  ll *ret = malloc(sizeof(ll));
  ret -> head = NULL;
  return ret;
}

void addInOrder(ll *l, void *elem, int (*cmp)(void*, void*)) {
  //l is valid haep allocated linked list
  //elem is a pointer to the data they want to add
  // and is heap allocated
  // cmp is a fucntion which takes pointers to the data
  // type we store in our list, and returns
  // >0 if first sorted before second
  // 0  if equal
  // <0 if first ordered after second

  llnode *prev = NULL;
  llnode *cur = l -> head;
  for (;cur && cmp(elem, cur->data)<0;prev=cur,cur=cur->next) {
    if (!prev) {
      addToFront(l, elem);
    }
    llnode *nn = malloc(sizeof(llnode));
    nn->next = cur;
    nn->data=elem;
    prev->next=nn;
  }
}

llnode *llnodecopy(llnode *n, void(*cpy)(void*, void*)) {
  if (!n) {
    return n; //same as return NULL
  }
  llnode *ret = malloc(sizeof(llnode));
  ret -> next = llnodecopy(n->next, cpy);
  ret->data = cpy(n->data)
}

//          //int *    //int **
void intcpy(void *src) {
  int *s = src;
  int *ret = malloc(sizeof((int));
  *ret = *s;
  return ret;
  //*d = malloc(sizeof(int));
  //**d = *s;
}

ll* llcopy(ll *l, void (*cpy)(void*)){
  ll *ret = malloc(sizeof(ll));
  ret->head = llnodecopy(l->head, cpy);
  return ret;
}

int intCmp (void *lhs, void*rhs) {
  return *(int *)lhs - *(int *)rhs;
}


// Exam question need to be able to have a better version of memset
// Cannot use loops or recursion