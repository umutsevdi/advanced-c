#include "../header/stk_util.h"
#include <stdio.h>

int stk_len(stk *stack) {
  int i;
  stk_node *n = stack->current;
  while (n->next != NULL) {
    n = n->next;
    i++;
  }
  return i;
}

int stk_cmp(stk_node *node1, stk_node *node2, int size) {
  if (&node1->value == &node2->value) {
    return 0;
  }
  return memcmp(node1->value, node2->value, size);
}

stk_node **stk2array(stk *stack) {
  int i = 0;
  int len = stk_len(stack);
  stk_node **arr = (stk_node **)malloc(len * sizeof(stk_node *));
  stk_node *c = stack->current;
  while (i < len) {
    arr[i++] = c;
    c = c->next;
  }
  return arr;
}

void stk_print(stk* stack ) {
    stk_node* c = stack->current;
    while(c!=NULL) {
        c=c->next;
        printf("%2d ",*(int*)c->value );
    }
    printf("\n");
}
