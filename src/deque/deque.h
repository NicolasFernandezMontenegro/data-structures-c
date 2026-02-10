#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include <stddef.h>


typedef struct deque deque_t;

/*
 * Creates an empty deque.
 * Returns NULL if memory allocation fails.
 */
deque_t* deque_create(void);

/*
 * Destroys the deque and frees all associated memory.
 * Undefined behavior if d is NULL.
 */
void deque_destroy(deque_t* d);

/*
 * Returns true if the deque is empty.
 * Undefined behavior if d is NULL.
 */
bool deque_is_empty(const deque_t* d);

/* 
 * Returns the number of elements currently stored in the deque.
 * Runs in O(1).
 * Undefined behavior if d is NULL.
 */ 
size_t deque_size(const deque_t* d);

/*
 * Inserts an element at the front of the deque.
 * Undefined behavior if d is NULL.
 */
void deque_push_front(deque_t* d, int value);

/*
 * Inserts an element at the back of the deque.
 * Undefined behavior if d is NULL.
 */
void deque_push_back(deque_t* d, int value);


/*
 * Removes the element at the front of the deque.
 * Undefined behavior if d is NULL or the deque is empty.
 */
void deque_pop_front(deque_t* d);


/*
 * Removes the element at the back of the deque.
 * Undefined behavior if d is NULL or the deque is empty.
 */
void deque_pop_back(deque_t* d);


/*
 * Returns the element at the front of the deque.
 * Undefined behavior if d is NULL or the deque is empty.
 */
int deque_front(const deque_t* d);


/*
 * Returns the element at the back of the deque.
 * Undefined behavior if d is NULL or the deque is empty.
 */
int deque_back(const deque_t* d);


#endif /* DEQUE_H */