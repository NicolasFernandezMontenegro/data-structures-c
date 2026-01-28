#include "queue.h"
#include "queue_internal.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

queue_t* queue_create(void){
    queue_t * q = malloc(sizeof(* q));
    if (q == NULL){
        return NULL;
    }
    q->repr = QUEUE_ARRAY;
    q->size = 0;
    q->impl.array.capacity = 0;
    q->impl.array.front = 0;
    q->impl.array.data = NULL;
    assert(queue_invariant(q));
    return q;
}


void queue_destroy(queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_ARRAY);
    if (q->impl.array.data != NULL){
        free(q->impl.array.data);   
    }
    free(q);
}


bool queue_is_empty(const queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_ARRAY);
    return q->size == 0;
}


size_t queue_size(const queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_ARRAY);
    return q->size;
}


void queue_enqueue(queue_t* q, int value){
    assert(queue_invariant(q) && q->repr == QUEUE_ARRAY);
    if (q->impl.array.capacity == 0){
        int new_cap = 1;
        int *new = malloc(sizeof(int) * new_cap);
        assert(new != NULL);
        q->impl.array.data = new;
        q->impl.array.front = 0;
        q->impl.array.capacity = new_cap;
    } else {
        if (q->size == q->impl.array.capacity){
            int new_cap = q->impl.array.capacity * 2;
            int *new = malloc(sizeof(int) * new_cap);
            assert(new != NULL);
            for (size_t i = 0; i < q->size; i++) {
                new[i] = q->impl.array.data[(q->impl.array.front + i) % q->impl.array.capacity];
            }
            free(q->impl.array.data);
            q->impl.array.data = new;
            q->impl.array.front = 0;
            q->impl.array.capacity = new_cap;
        }
    }
    
   
    int index = (q->impl.array.front + q->size) % q->impl.array.capacity;
    q->impl.array.data[index] = value;
    q->size++;
    
    assert(queue_invariant(q));
}


void queue_dequeue(queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_ARRAY && !queue_is_empty(q));
    q->impl.array.front = (q->impl.array.front + 1) % q->impl.array.capacity;
    q->size = q->size - 1;
    if (q->size == 0){
       q->impl.array.front = 0;
    }
    
    assert(queue_invariant(q));
}


int queue_front(const queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_ARRAY && !queue_is_empty(q));
    return q->impl.array.data[q->impl.array.front];
}