#ifndef STACK_INTERNAL_H
#define STACK_INTERNAL_H

#include <stdbool.h>
#include <stddef.h>
#include <assert.h>


typedef enum {
    STACK_ARRAY,
    STACK_LIST
} stack_repr_t;

/* Node used by the linked-list implementation */
typedef struct stack_node {
    int value;
    struct stack_node* next;
} stack_node_t;

/* Concrete stack structure */
struct stack {
    stack_repr_t repr;
    size_t size;

    union {
        struct {
            int* data;
            size_t capacity;
        } array;

        struct {
            stack_node_t* top;
        } list;
    } impl;
};


/*
 * Checks whether the stack satisfies its representation invariants.
 * This function is intended to be used with assert().
 */
bool stack_invariant(const struct stack* s);

#endif /* STACK_INTERNAL_H */
