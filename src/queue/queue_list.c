#include "queue.h"
#include "queue_internal.h"
#include <stdlib.h>

queue_t* queue_create(void){
    queue_t * q = malloc(sizeof(* q));
    if (q == NULL){
        return NULL;
    }
    q->repr = QUEUE_LIST;
    q->size = 0;
    q->impl.list.back = NULL;
    q->impl.list.front = NULL;
    assert(queue_invariant(q));
    return q;
}


void queue_destroy(queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_LIST);
    queue_node_t *nxt = NULL;
    nxt = q->impl.list.front;
    while (nxt != NULL){
       nxt = q->impl.list.front->next;
       free(q->impl.list.front);
       q->impl.list.front = nxt;
    }
    free(q);
}


bool queue_is_empty(const queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_LIST);
    return q->size == 0;
}


size_t queue_size(const queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_LIST);
    return q->size;
}


void queue_enqueue(queue_t* q, int value){
    assert(queue_invariant(q) && q->repr == QUEUE_LIST);
    queue_node_t *new = malloc(sizeof(queue_node_t));
    assert(new != NULL);
    new->next = NULL;
    new->value = value;
    if (q->size == 0){
        q->impl.list.front = new;
        q->impl.list.back = new;
    } else {
        q->impl.list.back->next = new;
        q->impl.list.back = new;

    }
    
    q->size = q->size + 1;
    assert(queue_invariant(q));
}


void queue_dequeue(queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_LIST && !queue_is_empty(q));
    queue_node_t *tmp = q->impl.list.front->next; 
    free(q->impl.list.front);
    q->impl.list.front = tmp;
    q->size = q->size - 1;
    if (q->size == 0){
        q->impl.list.back = NULL;
    }
    assert(queue_invariant(q));
}


int queue_front(const queue_t* q){
    assert(queue_invariant(q) && q->repr == QUEUE_LIST && !queue_is_empty(q));
    return q->impl.list.front->value;
}