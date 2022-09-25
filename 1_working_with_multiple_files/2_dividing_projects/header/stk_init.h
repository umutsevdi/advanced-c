#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * stk_node represents each element in the stack
 */
typedef struct STK_NODE {
  void *value;
  struct STK_NODE *next;
} stk_node;

/*
 * stk_stack represents an entire stack
 */
typedef struct STK_STACK {
  stk_node *head;
  stk_node *current;
} stk;

/**
 * allocates a new stk_node and returns it's address
 * @param   value Value to be inserted into the node
 * @return  address of the stack node
 */
stk_node *stk_new_node(void *value);

/**
 * allocates a new stack, if the given element is NULL,
 * returns NULL instead
 * @param node  first element
 * @return      address of the new stack
 */
stk *stk_new(stk_node *node);
