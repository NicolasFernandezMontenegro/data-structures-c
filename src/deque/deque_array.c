#include "deque.h"
#include "deque_internal.h"
#include <stdlib.h>



deque_t* deque_create(void){
    deque_t * d = malloc(sizeof(* d));
    if (d == NULL){
        return NULL;
    }
    d->repr = DEQUE_ARRAY;
    d->size = 0;
    d->impl.array.capacity = 0;
    d->impl.array.data = NULL;
    d->impl.array.front = 0;
    assert(deque_invariant(d));
    return d;
}


void deque_destroy(deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_ARRAY);
    if (d->impl.array.data != NULL){
        free(d->impl.array.data);   
    }
    free(d);
}


bool deque_is_empty(const deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_ARRAY);
    return d->size == 0;
}


size_t deque_size(const deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_ARRAY);
    return d->size;
}


void deque_push_front(deque_t* d, int value){
    assert(deque_invariant(d) && d->repr == DEQUE_ARRAY);
    if (d->impl.array.capacity == 0){
        size_t new_cap = 4; 
        int *new = malloc(sizeof(int) * new_cap);
        assert(new != NULL);
        d->impl.array.data = new;
        d->impl.array.capacity = new_cap;
        d->impl.array.front = 0;
    } else {
        if (d->impl.array.capacity == d->size){
            size_t new_cap = d->impl.array.capacity * 2;
            int * new = malloc(sizeof(int) * new_cap);
            assert(new != NULL);
            for (size_t i = 1; i < d->size; i++){
                new[i] = d->impl.array.data[(d->impl.array.front + i) % d->impl.array.capacity];
            }
            free(d->impl.array.data);
            d->impl.array.data = new;
            d->impl.array.capacity = new_cap;
            d->impl.array.front = 0;
        } else {
            d->impl.array.front = (d->impl.array.front - 1 + d->impl.array.capacity) % d->impl.array.capacity;
           
        }
    }
    d->impl.array.data[d->impl.array.front] = value;
    d->size++;
    assert(deque_invariant(d));
}


void deque_push_back(deque_t* d, int value){
    assert(deque_invariant(d) && d->repr == DEQUE_ARRAY);
    if (d->impl.array.capacity == 0){
        size_t new_cap = 4; 
        int *new = malloc(sizeof(int) * new_cap);
        assert(new != NULL);
        d->impl.array.data = new;
        d->impl.array.capacity = new_cap;
        d->impl.array.front = 0;
    } else {
        if (d->impl.array.capacity == d->size){
            size_t new_cap = d->impl.array.capacity * 2;
            int * new = malloc(sizeof(int) * new_cap);
            assert(new != NULL);
            for (size_t i = 0; i < d->size; i++){
                new[i] = d->impl.array.data[(d->impl.array.front + i) % d->impl.array.capacity];
            }
            free(d->impl.array.data);
            d->impl.array.data = new;
            d->impl.array.capacity = new_cap;
            d->impl.array.front = 0;
        }
    }
    d->impl.array.data[(d->impl.array.front + d->size) % d->impl.array.capacity] = value;
    d->size++;
    assert(deque_invariant(d));
}


void deque_pop_front(deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_ARRAY && !deque_is_empty(d) && d->impl.array.capacity > 0);
    d->impl.array.front = (d->impl.array.front + 1) % d->impl.array.capacity;
    d->size = d->size - 1;
    if (d->size == 0){
       d->impl.array.front = 0;
    }
    
    assert(deque_invariant(d));
}


void deque_pop_back(deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_ARRAY && !deque_is_empty(d));
    d->size = d->size - 1;
    if (d->size == 0){
       d->impl.array.front = 0;
    }
    assert(deque_invariant(d));
}


int deque_front(const deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_ARRAY && !deque_is_empty(d));
    return d->impl.array.data[d->impl.array.front];
}


int deque_back(const deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_ARRAY && !deque_is_empty(d));

    return d->impl.array.data[(d->impl.array.front + d->size - 1) % d->impl.array.capacity];
}