#ifndef STK_INIT
#define STK_INIT
#include "stk_init.h"
#endif

/**
 * returns the size of the stack
 * @param  stk*      stack address of the stack
 * @return size of the stack
 */
int stk_len(stk *stack);

/**
 * Compares two stack nodes and returns a value
 * @param stk_node *node1 First node
 * @param stk_node *node2 Second node
 * @return return 0 if the values are equal, 1 otherwise
 */
int stk_cmp(stk_node *node1, stk_node *node2, int s_type);

/**
 * returns all elements in the stack as an array
 * without popping them
 * @param  stk*      stack address of the stack
 * @return address of an allocated array
 */
stk_node **stk2array(stk *stack);

void stk_print(stk* stack );
