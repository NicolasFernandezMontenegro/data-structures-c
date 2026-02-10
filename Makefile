CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -Werror -g

SRC = src

# =======================
# Stack
# =======================
STACK_DIR = $(SRC)/stack

STACK_ARRAY_SRC = $(STACK_DIR)/stack_array.c
STACK_LIST_SRC  = $(STACK_DIR)/stack_list.c
STACK_INTERNAL  = $(STACK_DIR)/stack_internal.c
STACK_TEST      = $(STACK_DIR)/test_stack.c

BIN_STACK_ARRAY = test_stack_array
BIN_STACK_LIST  = test_stack_list

# =======================
# Queue
# =======================
QUEUE_DIR = $(SRC)/queue

QUEUE_ARRAY_SRC = $(QUEUE_DIR)/queue_array.c
QUEUE_LIST_SRC  = $(QUEUE_DIR)/queue_list.c
QUEUE_INTERNAL  = $(QUEUE_DIR)/queue_internal.c
QUEUE_TEST      = $(QUEUE_DIR)/test_queue.c

BIN_QUEUE_ARRAY = test_queue_array
BIN_QUEUE_LIST  = test_queue_list

# =======================
# Deque
# =======================
DEQUE_DIR = $(SRC)/deque

DEQUE_ARRAY_SRC = $(DEQUE_DIR)/deque_array.c
DEQUE_LIST_SRC  = $(DEQUE_DIR)/deque_list.c
DEQUE_INTERNAL  = $(DEQUE_DIR)/deque_internal.c
DEQUE_TEST      = $(DEQUE_DIR)/test_deque.c

BIN_DEQUE_ARRAY = test_deque_array
BIN_DEQUE_LIST  = test_deque_list


# =======================
# Targets
# =======================
.PHONY: all stack queue deque clean

all: stack queue deque


stack: $(BIN_STACK_ARRAY) $(BIN_STACK_LIST)
queue: $(BIN_QUEUE_ARRAY) $(BIN_QUEUE_LIST)
deque: $(BIN_DEQUE_ARRAY) $(BIN_DEQUE_LIST)

# =======================
# Stack builds
# =======================
$(BIN_STACK_ARRAY): $(STACK_ARRAY_SRC) $(STACK_INTERNAL) $(STACK_TEST)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_STACK_LIST): $(STACK_LIST_SRC) $(STACK_INTERNAL) $(STACK_TEST)
	$(CC) $(CFLAGS) $^ -o $@

# =======================
# Queue builds
# =======================
$(BIN_QUEUE_ARRAY): $(QUEUE_ARRAY_SRC) $(QUEUE_INTERNAL) $(QUEUE_TEST)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_QUEUE_LIST): $(QUEUE_LIST_SRC) $(QUEUE_INTERNAL) $(QUEUE_TEST)
	$(CC) $(CFLAGS) $^ -o $@

# =======================
# Deque builds
# =======================
$(BIN_DEQUE_ARRAY): $(DEQUE_ARRAY_SRC) $(DEQUE_INTERNAL) $(DEQUE_TEST)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_DEQUE_LIST): $(DEQUE_LIST_SRC) $(DEQUE_INTERNAL) $(DEQUE_TEST)
	$(CC) $(CFLAGS) $^ -o $@


# =======================
# Clean
# =======================
clean:
	rm -f \
	$(BIN_STACK_ARRAY) $(BIN_STACK_LIST) \
	$(BIN_QUEUE_ARRAY) $(BIN_QUEUE_LIST) \
	$(BIN_DEQUE_ARRAY) $(BIN_DEQUE_LIST)

