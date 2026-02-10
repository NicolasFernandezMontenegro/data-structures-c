#ifndef DEQUE_INTERNAL_H
#define DEQUE_INTERNAL_H

#include <stdbool.h>
#include <stddef.h>
#include <assert.h>


typedef enum {
    DEQUE_ARRAY,
    DEQUE_LIST
} deque_repr_t;

/* Node used by the linked-list implementation */
typedef struct deque_node {
    int value;
    struct deque_node *prev;
    struct deque_node *next;
} deque_node_t;


/* Concrete deque structure */
struct deque {
    deque_repr_t repr;
    size_t size;
    union {
        struct {
            int*   data;
            size_t capacity;
            size_t front;
        } array;
        struct {
            struct deque_node* front;
            struct deque_node* back;
        } list;
    } impl;
};


/*
 * Checks whether the deque satisfies its representation invariants.
 * This function is intended to be used with assert().
 */
bool deque_invariant(const struct deque* d);

#endif /* DEQUE_INTERNAL_H */