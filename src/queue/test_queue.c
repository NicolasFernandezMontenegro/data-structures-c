#include "queue.h"
#include <assert.h>
#include <stdio.h>

#define N 1000

static void test_create_and_empty(void) {
    queue_t *q = queue_create();
    assert(q != NULL);
    assert(queue_is_empty(q));
    assert(queue_size(q) == 0);
    queue_destroy(q);
}

static void test_single_enqueue(void) {
    queue_t *q = queue_create();
    queue_enqueue(q, 42);

    assert(!queue_is_empty(q));
    assert(queue_size(q) == 1);
    assert(queue_front(q) == 42);

    queue_destroy(q);
}

static void test_fifo_order(void) {
    queue_t *q = queue_create();

    for (int i = 0; i < N; i++) {
        queue_enqueue(q, i);
        assert(queue_front(q) == 0);
    }

    for (int i = 0; i < N; i++) {
        assert(!queue_is_empty(q));
        assert(queue_front(q) == i);
        queue_dequeue(q);
    }

    assert(queue_is_empty(q));
    assert(queue_size(q) == 0);

    queue_destroy(q);
}

static void test_interleaved_operations(void) {
    queue_t *q = queue_create();

    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    queue_dequeue(q);              
    assert(queue_front(q) == 2);

    queue_enqueue(q, 3);
    assert(queue_front(q) == 2);

    queue_dequeue(q);              
    assert(queue_front(q) == 3);

    queue_dequeue(q);              
    assert(queue_is_empty(q));

    queue_destroy(q);
}

static void test_dequeue_until_empty(void) {
    queue_t *q = queue_create();

    for (int i = 0; i < 10; i++) {
        queue_enqueue(q, i);
    }

    for (int i = 0; i < 10; i++) {
        assert(queue_front(q) == i);
        queue_dequeue(q);
    }

    assert(queue_is_empty(q));
    assert(queue_size(q) == 0);

    queue_destroy(q);
}

int main(void) {
    test_create_and_empty();
    test_single_enqueue();
    test_fifo_order();
    test_interleaved_operations();
    test_dequeue_until_empty();

    printf("All queue tests passed successfully.\n");
    return 0;
}
