#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

/*
 * Opaque stack type.
 * The internal representation is hidden from the user.
 */
typedef struct stack stack_t;

/*
 * Creates an empty stack.
 * Returns NULL if memory allocation fails.
 */
stack_t* stack_create(void);

/*
 * Destroys the stack and frees all associated memory.
 * Undefined behavior if s is NULL.
 */
void stack_destroy(stack_t* s);

/*
 * Returns true if the stack is empty.
 * Undefined behavior if s is NULL.
 */
bool stack_is_empty(const stack_t* s);

/*
 * Returns the number of elements currently stored in the stack.
 * Runs in O(1).
 * Undefined behavior if s is NULL.
 */
size_t stack_size(const stack_t* s);

/*
 * Pushes a value onto the top of the stack.
 * Undefined behavior if s is NULL.
 */
void stack_push(stack_t* s, int value);

/*
 * Returns the value at the top of the stack without removing it.
 * Undefined behavior if s is NULL or the stack is empty.
 */
int stack_top(const stack_t* s);

/*
 * Removes the top element from the stack.
 * Undefined behavior if s is NULL or the stack is empty.
 */
void stack_pop(stack_t* s);

#endif /* STACK_H */
