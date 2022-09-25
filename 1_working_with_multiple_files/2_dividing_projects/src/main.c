#include "../header/stk.h"

int main(int argc, char *argv[]) {
  int i = 0;
  stk *stack = stk_new(stk_new_node(&i));
  printf("stk_new is working %p %p = %d\n", stack->current,
         stack->current->value, *(int *)stack->current->value);

  for (i = 0; i < 5; i++) {
    stk_node *s = stk_new_node(&i);
    int r = stk_push(stack, s);
    if (!r) {
      printf("pushed:\t%2d\n", *(int *)s->value);
    }
  }
  stk_print(stack);
  int status = 1;
  stk_node *c;
  do {
    c = stk_pop(stack);
    if (c) {
      printf("pop:%p -> %2d\n", c, *(int *)c->value);
    } else {
      printf("err:STK_ERROR_NO_ELEMENT_LEFT\n");
    }
    free(c);
  } while (c);
  free(stack);
  return 0;
}
