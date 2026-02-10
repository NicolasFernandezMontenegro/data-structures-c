#include "deque.h"
#include <assert.h>
#include <stdio.h>

static void test_create_destroy(void) {
    deque_t *d = deque_create();
    assert(d != NULL);
    assert(deque_is_empty(d));
    assert(deque_size(d) == 0);
    deque_destroy(d);
}

static void test_push_front(void) {
    deque_t *d = deque_create();

    deque_push_front(d, 10);
    assert(!deque_is_empty(d));
    assert(deque_size(d) == 1);
    assert(deque_front(d) == 10);
    assert(deque_back(d) == 10);

    deque_push_front(d, 20);
    assert(deque_size(d) == 2);
    assert(deque_front(d) == 20);
    assert(deque_back(d) == 10);

    deque_destroy(d);
}

static void test_push_back(void) {
    deque_t *d = deque_create();

    deque_push_back(d, 10);
    assert(deque_size(d) == 1);
    assert(deque_front(d) == 10);
    assert(deque_back(d) == 10);

    deque_push_back(d, 20);
    assert(deque_size(d) == 2);
    assert(deque_front(d) == 10);
    assert(deque_back(d) == 20);

    deque_destroy(d);
}

static void test_pop_front(void) {
    deque_t *d = deque_create();

    deque_push_back(d, 1);
    deque_push_back(d, 2);
    deque_push_back(d, 3);

    deque_pop_front(d);
    assert(deque_size(d) == 2);
    assert(deque_front(d) == 2);
    assert(deque_back(d) == 3);

    deque_pop_front(d);
    deque_pop_front(d);
    assert(deque_is_empty(d));

    deque_destroy(d);
}

static void test_pop_back(void) {
    deque_t *d = deque_create();

    deque_push_front(d, 1);
    deque_push_front(d, 2);
    deque_push_front(d, 3);

    deque_pop_back(d);
    assert(deque_size(d) == 2);
    assert(deque_front(d) == 3);
    assert(deque_back(d) == 2);

    deque_pop_back(d);
    deque_pop_back(d);
    assert(deque_is_empty(d));

    deque_destroy(d);
}

static void test_mixed_operations(void) {
    deque_t *d = deque_create();

    deque_push_back(d, 1);
    deque_push_front(d, 2);
    deque_push_back(d, 3);

    assert(deque_front(d) == 2);
    assert(deque_back(d) == 3);
    assert(deque_size(d) == 3);

    deque_pop_front(d);      
    assert(deque_front(d) == 1);

    deque_pop_back(d);
    assert(deque_front(d) == 1);
    assert(deque_back(d) == 1);

    deque_pop_front(d);
    assert(deque_is_empty(d));

    deque_destroy(d);
}

static void test_stress_order(void) {
    deque_t *d = deque_create();
    const int N = 1000;

    for (int i = 0; i < N; i++) {
        deque_push_back(d, i);
    }

    for (int i = 0; i < N; i++) {
        assert(deque_front(d) == i);
        deque_pop_front(d);
    }

    assert(deque_is_empty(d));
    deque_destroy(d);
}

int main(void) {
    test_create_destroy();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_mixed_operations();
    test_stress_order();

    printf("All deque tests passed successfully.\n");
    return 0;
}
