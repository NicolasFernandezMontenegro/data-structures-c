#include <assert.h>
#include <stdio.h>
#include "stack.h"

static void test_create_empty(void) {
    stack_t *s = stack_create();
    assert(s != NULL);
    assert(stack_is_empty(s));
    assert(stack_size(s) == 0);
    stack_destroy(s);
}


static void test_push_and_top(void) {
    stack_t *s = stack_create();

    stack_push(s, 10);
    assert(!stack_is_empty(s));
    assert(stack_size(s) == 1);
    assert(stack_top(s) == 10);

    stack_push(s, 20);
    assert(stack_size(s) == 2);
    assert(stack_top(s) == 20);

    stack_destroy(s);
}


static void test_push_pop_sequence(void) {
    stack_t *s = stack_create();

    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);

    assert(stack_top(s) == 3);
    stack_pop(s);
    assert(stack_top(s) == 2);

    stack_pop(s);
    assert(stack_top(s) == 1);

    stack_pop(s);
    assert(stack_is_empty(s));
    assert(stack_size(s) == 0);

    stack_destroy(s);
}

static void test_interleaved_operations(void) {
    stack_t *s = stack_create();

    stack_push(s, 5);
    stack_push(s, 6);
    stack_pop(s);
    stack_push(s, 7);

    assert(stack_top(s) == 7);
    assert(stack_size(s) == 2);

    stack_pop(s);
    assert(stack_top(s) == 5);

    stack_destroy(s);
}


static void test_many_pushes(void) {
    stack_t *s = stack_create();

    const size_t N = 1000;
    for (size_t i = 0; i < N; i++) {
        stack_push(s, (int)i);
        assert(stack_top(s) == (int)i);
    }

    assert(stack_size(s) == N);

    for (size_t i = N; i-- > 0; ) {
        assert(stack_top(s) == (int)i);
        stack_pop(s);
    }

    assert(stack_is_empty(s));
    stack_destroy(s);
}


int main(void) {
    test_create_empty();
    test_push_and_top();
    test_push_pop_sequence();
    test_interleaved_operations();
    test_many_pushes();

    printf("All stack tests passed successfully.\n");
    return 0;
}
