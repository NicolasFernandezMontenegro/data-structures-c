#include "stack.h"
#include "stack_internal.h"
#include <stdlib.h>


stack_t* stack_create(void){
    stack_t* s = malloc(sizeof(* s));
    if (s == NULL) {
        return NULL;
    }
    s->repr = STACK_LIST;
    s->size = 0;
    s->impl.list.top = NULL;
    assert(stack_invariant(s));
    return s;
}


void stack_destroy(stack_t* s){
    assert(stack_invariant(s) && s->repr == STACK_LIST);
    stack_node_t *nxt = NULL;
    nxt = s->impl.list.top;
    while (nxt != NULL){
       nxt = s->impl.list.top->next;
       free(s->impl.list.top);
       s->impl.list.top = nxt;
    }
    free(s);
}


bool stack_is_empty(const stack_t* s){
    assert(stack_invariant(s) && s->repr == STACK_LIST);
    return s->size == 0;
}

size_t stack_size(const stack_t* s){
    assert(stack_invariant(s) && s->repr == STACK_LIST);
    return s->size;
}



void stack_push(stack_t* s, int value) {
    assert(stack_invariant(s) && s->repr == STACK_LIST);
    stack_node_t *new = malloc(sizeof(stack_node_t));
    assert(new != NULL);
    new->value = value;
    new->next = s->impl.list.top;
    s->impl.list.top = new;
    s->size = s->size + 1;
    assert(stack_invariant(s));
}

int stack_top(const stack_t* s){
   assert(stack_invariant(s) && s->repr == STACK_LIST && !stack_is_empty(s));
   return s->impl.list.top->value;
}


void stack_pop(stack_t* s){
    assert(stack_invariant(s) && s->repr == STACK_LIST && !stack_is_empty(s));
    stack_node_t *tmp = s->impl.list.top->next;
    free(s->impl.list.top);
    s->impl.list.top = tmp;
    s->size = s->size - 1;
    assert(stack_invariant(s));
}