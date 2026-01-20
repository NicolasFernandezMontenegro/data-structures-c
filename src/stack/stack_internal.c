#include "stack_internal.h"

bool stack_invariant(const struct stack* s){
    bool check = false;
    size_t nodes = 0;
    stack_node_t* current = NULL;
    if (s != NULL){
        if (s->repr == STACK_ARRAY){
            check = s->impl.array.capacity >= s->size;
            if (s->impl.array.capacity > 0){
                    check = s->impl.array.data != NULL;
            } else if (s->impl.array.capacity == 0){
                    check = s->impl.array.data == NULL;
            }      
        } else if (s->repr == STACK_LIST){
            if (s->size == 0){
                check = s->impl.list.top == NULL;
            } else if (s->size > 0) {
                if (s->impl.list.top != NULL){
                    current = s->impl.list.top;
                    while (current != NULL){
                        nodes++;
                        current = current->next;
                    }
                    if (nodes == s->size){
                        check = true;
                    } 
                } else {
                    check = false;      
                }    
            }
        } else {
            check = false;
        }      
    }
    return check;
}