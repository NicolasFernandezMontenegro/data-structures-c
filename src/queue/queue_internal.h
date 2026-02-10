#ifndef QUEUE_INTERNAL_H
#define QUEUE_INTERNAL_H

#include <stdbool.h>
#include <stddef.h>
#include <assert.h>


typedef enum {
    QUEUE_ARRAY,
    QUEUE_LIST
} queue_repr_t;

/* Node used by the linked-list implementation */
typedef struct queue_node {
    int value;
    struct queue_node* next;
} queue_node_t;

/* Concrete queue structure */
struct queue {
    queue_repr_t repr;
    size_t size;
    union {
        struct {
            int*   data;
            size_t capacity;
            size_t front;
        } array;
        struct {
            struct queue_node* front;
            struct queue_node* back;
        } list;
    } impl;
};


/*
 * Checks whether the queue satisfies its representation invariants.
 * This function is intended to be used with assert().
 */
bool queue_invariant(const struct queue* q);

#endif /* QUEUE_INTERNAL_H */