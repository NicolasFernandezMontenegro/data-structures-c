#include "queue_internal.h"


bool queue_invariant(const struct queue* q){
    bool check = false;
    if (q != NULL){
        if (q->repr == QUEUE_ARRAY){
            if (q->impl.array.capacity != 0){
                if (q->impl.array.capacity >= q->size){
                    if (q->impl.array.capacity > 0){
                        check = q->impl.array.data != NULL && 
                                q->impl.array.front < q->impl.array.capacity;
                    } 
                }
            } else {
                check = q->impl.array.data == NULL && q->impl.array.front == 0 && q->size == 0;
            }
        }
        else if (q->repr == QUEUE_LIST){
            if (q->size == 0){
                check = q->impl.list.front == NULL && q->impl.list.back == NULL;
            }
            else if (q->size > 0){
                size_t nodes = 0;
                struct queue_node* current = q->impl.list.front;
                if (q->impl.list.front != NULL && q->impl.list.back != NULL && q->impl.list.back->next == NULL){
                    while (current != NULL){
                        nodes++;
                        if (current->next == NULL){
                            check = (current == q->impl.list.back);
                        }
                        current = current->next;
                    }
                    check = check && nodes == q->size;
                }
            }
        }              
    }
    return check;
}

