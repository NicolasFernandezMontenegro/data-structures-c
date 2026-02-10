#include "deque_internal.h"


bool deque_invariant(const struct deque* d){ 
    bool check = false;

    if (d != NULL){
        if (d->repr == DEQUE_ARRAY){
            if (d->impl.array.capacity != 0){
                check =
                    d->impl.array.data != NULL &&
                    d->impl.array.capacity >= d->size &&
                    d->impl.array.front < d->impl.array.capacity &&
                    (d->size != 0 || d->impl.array.front == 0);
            } else {
                check =
                    d->impl.array.data == NULL &&
                    d->size == 0 &&
                    d->impl.array.front == 0;
            }
        }
        else if (d->repr == DEQUE_LIST){
            if (d->size == 0){
                check =
                    d->impl.list.front == NULL &&
                    d->impl.list.back == NULL;
            }
            else if (d->size == 1){
                check =
                    d->impl.list.front != NULL &&
                    d->impl.list.back != NULL &&
                    d->impl.list.front == d->impl.list.back &&
                    d->impl.list.front->prev == NULL &&
                    d->impl.list.back->next == NULL;
            }
            else { 
                size_t nodes = 0;
                struct deque_node* current = d->impl.list.front;

                if (d->impl.list.front != NULL &&
                    d->impl.list.back != NULL &&
                    d->impl.list.front->prev == NULL &&
                    d->impl.list.back->next == NULL){

                    check = true;

                    while (current != NULL && check){
                        nodes++;

                        if (current->next != NULL &&
                            current->next->prev != current){
                            check = false;
                        }

                        if (current->next == NULL &&
                            current != d->impl.list.back){
                            check = false;
                        }

                        current = current->next;
                    }

                    check = check && (nodes == d->size);
                }
            }
        }
    }

    return check;
}
