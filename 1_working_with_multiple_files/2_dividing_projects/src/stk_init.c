#include "../header/stk_init.h"
#include <stdlib.h>

stk_node *stk_new_node(void *value) {
  stk_node *node = (stk_node *)malloc(sizeof(stk_node));
  node->value = value;
  return node;
}

stk *stk_new(stk_node *node) {
  if (node == NULL) {
    return NULL;
  }
  stk *stack = (stk *)malloc(sizeof(stk));
  stack->current = node;
  stack->head = node;
  return stack;
}
