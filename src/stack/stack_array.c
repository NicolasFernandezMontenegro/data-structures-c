#include "stack.h"
#include "stack_internal.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


stack_t* stack_create(void){
    stack_t* s = malloc(sizeof(* s));
    if (s == NULL) {
        return NULL;
    }
    s->repr = STACK_ARRAY;
    s->size = 0;
    s->impl.array.data = NULL;
    s->impl.array.capacity = 0;
    assert(stack_invariant(s));
    return s;
}


void stack_destroy(stack_t* s){
    assert(stack_invariant(s) && s->repr == STACK_ARRAY);
    if (s->impl.array.data != NULL){
        free(s->impl.array.data);
        s->impl.array.data = NULL;
        s->impl.array.capacity = 0;
    }
    s->size = 0;
    free(s);
}


bool stack_is_empty(const stack_t* s){
    assert(stack_invariant(s) && s->repr == STACK_ARRAY);
    return s->size == 0;
}

size_t stack_size(const stack_t* s){
    assert(stack_invariant(s) && s->repr == STACK_ARRAY);
    return s->size;

}



void stack_push(stack_t* s, int value) {
    assert(stack_invariant(s) && s->repr == STACK_ARRAY);

    if (s->size == s->impl.array.capacity) {
        size_t new_capacity;

        if (s->impl.array.capacity == 0) {
            new_capacity = 1;
        } else {
            new_capacity = s->impl.array.capacity * 2;
        }

        int *temp = realloc(
            s->impl.array.data,
            new_capacity * sizeof(*s->impl.array.data)
        );

        assert(temp != NULL);

        s->impl.array.data = temp;
        s->impl.array.capacity = new_capacity;
    }

    s->impl.array.data[s->size] = value;
    s->size++;

    assert(stack_invariant(s));
}

int stack_top(const stack_t* s){
    assert(stack_invariant(s) && s->repr == STACK_ARRAY && !stack_is_empty(s));
    return s->impl.array.data[s->size - 1];
}


void stack_pop(stack_t* s){
    assert(stack_invariant(s) && s->repr == STACK_ARRAY && !stack_is_empty(s));
    s->size = s->size - 1;
    assert(stack_invariant(s));
}