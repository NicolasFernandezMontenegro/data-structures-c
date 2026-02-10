#include "deque.h"
#include "deque_internal.h"
#include <stdlib.h>



deque_t* deque_create(void){
    deque_t * d = malloc(sizeof(* d));
    if (d == NULL){
        return NULL;
    }
    d->repr = DEQUE_LIST;
    d->size = 0;
    d->impl.list.front = NULL;
    d->impl.list.back = NULL;
    assert(deque_invariant(d));
    return d;
}


void deque_destroy(deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_LIST);
    deque_node_t *nxt = NULL;
    nxt = d->impl.list.front;
    while (nxt != NULL){
       nxt = d->impl.list.front->next;
       free(d->impl.list.front);
       d->impl.list.front = nxt;
    }
    free(d);
}


bool deque_is_empty(const deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_LIST);
    return d->size == 0;
}


size_t deque_size(const deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_LIST);
    return d->size;
}


void deque_push_front(deque_t* d, int value){
    assert(deque_invariant(d) && d->repr == DEQUE_LIST);
    deque_node_t *new = malloc(sizeof(deque_node_t));
    assert(new != NULL);
    new->prev = NULL;
    new->value = value;
    if (d->size == 0){
        new->next =NULL;   
        d->impl.list.front = new;
        d->impl.list.back = new;
    } else {
        d->impl.list.front->prev = new;
        new->next = d->impl.list.front;
        d->impl.list.front = new;
    }
    d->size = d->size + 1;
    assert(deque_invariant(d));
}


void deque_push_back(deque_t* d, int value){
    assert(deque_invariant(d) && d->repr == DEQUE_LIST);
    deque_node_t *new = malloc(sizeof(deque_node_t));
    assert(new != NULL);
    new->next = NULL;
    new->value = value;
    if (d->size == 0){
        new->prev =NULL;   
        d->impl.list.front = new;
        d->impl.list.back = new;
    } else {
        d->impl.list.back->next = new;
        new->prev = d->impl.list.back;
        d->impl.list.back = new;
    }
    d->size = d->size + 1;
    assert(deque_invariant(d));
}


void deque_pop_front(deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_LIST && !deque_is_empty(d));
    deque_node_t *tmp = d->impl.list.front->next;
    free(d->impl.list.front);
    d->impl.list.front = tmp;
    d->size = d->size - 1;
    if (d->size == 0){
        d->impl.list.back = NULL;
    } else {
        d->impl.list.front->prev = NULL;
    }
    assert(deque_invariant(d));
}


void deque_pop_back(deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_LIST && !deque_is_empty(d));
    deque_node_t *tmp = d->impl.list.back->prev;
    free(d->impl.list.back);
    d->impl.list.back = tmp;
    d->size = d->size - 1;
    if (d->size == 0){
        d->impl.list.front = NULL;
    } else {
        d->impl.list.back->next = NULL;
    }
    assert(deque_invariant(d));
}


int deque_front(const deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_LIST && !deque_is_empty(d));
    return d->impl.list.front->value;
}


int deque_back(const deque_t* d){
    assert(deque_invariant(d) && d->repr == DEQUE_LIST && !deque_is_empty(d));
    return d->impl.list.back->value;
}