#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct queue queue_t;

/*
 * Creates an empty queue.
 * Returns NULL if memory allocation fails.
 */
queue_t* queue_create(void);

/*
 * Destroys the queue and frees all associated memory.
 * Undefined behavior if q is NULL.
 */
void queue_destroy(queue_t* q);

/*
 * Returns true if the queue is empty.
 * Undefined behavior if q is NULL.
 */
bool queue_is_empty(const queue_t* q);

/* 
 * Returns the number of elements currently stored in the queue.
 * Runs in O(1).
 * Undefined behavior if q is NULL.
 */ 
size_t queue_size(const queue_t* q);

/*
 * Adds the given value to the end of the queue.
 * Undefined behavior if q is NULL.
 */
void queue_enqueue(queue_t* q, int value);


/*
 * Removes the element at the front of the queue.
 * Undefined behavior if q is NULL or the queue is empty.
 */
void queue_dequeue(queue_t* q);

/*
 * Returns the value at the front of the queue without removing it.
 * Undefined behavior if q is NULL or the queue is empty.
 */
int queue_front(const queue_t* q);


#endif /* QUEUE_H */