#ifndef STK_INIT
#define STK_INIT
#include "stk_init.h"
#endif

#ifndef STK_UTIL
#define STK_UTIL
#include "stk_util.h"
#endif

#include <stdlib.h>

#define STK_ERROR_ALREADY_ADDED 1
#define STK_ERROR_INVALID_ARGUMENTS 2
#define STK_ERROR_NO_ELEMENT_LEFT NULL

/**
 * pushes given node to the stack
 * @param stk*      stack address of the stack
 * @param stk_node* address of the node
 * @return 0 if successfully pushed, any other number on error
 */
int stk_push(stk *stack, stk_node *node);

/**
 * pushes all given elements to the stack
 * @param stk*      stack address of the stack
 * @param stk_node* address of the node
 */
void stk_push_all(stk *stack, stk_node *nodes, ...);

/**
 * pops an element from the stack and writes it to an argument;
 * @param  stk*      stack address of the stack
 * @return stk_node* element to write the address
 */
stk_node *stk_pop(stk *stack);

/**
 * pops an element from the stack n times and returns the last element
 * @param  stk*      stack address of the stack
 * @return stk_node* address of the node
 */
stk_node *stk_pop_times(stk *stack, int times);

/**
 * pops all elements in the stack and adds them into an array
 * @param stk*       stack address of the stack
 * @return stk_node* address of the node array
 */
stk_node **stk_pop_all(stk *stack);
