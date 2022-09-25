#include "../header/stk_mv.h"

int stk_push(stk *stack, stk_node *node) {
  if (stack == NULL || node == NULL) {
    return STK_ERROR_INVALID_ARGUMENTS;
  } else if (stack->current == node) {
    return STK_ERROR_ALREADY_ADDED;
  }
  node->next = stack->current;
  stack->current = node;
  return 0;
}

void stk_push_all(stk *stack, stk_node *nodes, ...);

stk_node *stk_pop(stk *stack) {
  if (stack->current == NULL) {
    return STK_ERROR_NO_ELEMENT_LEFT;
  }
  stk_node *c = stack->current;
  stack->current = c->next;
  c->next = NULL;
  return c;
}

stk_node *stk_pop_times(stk *stack, int times) {
  int i;
  stk_node *node;
  while (!(node = stk_pop(stack)) && i < times) {
    i++;
  }
  return node->value;
}

stk_node **stk_pop_all(stk *stack) {
  printf("NOT_IMPLEMENTED");
  return NULL;
}
