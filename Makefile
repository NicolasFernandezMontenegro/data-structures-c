CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -Werror -g

SRC     = src


ARRAY_SRC = $(SRC)/stack/stack_array.c
LIST_SRC  = $(SRC)/stack/stack_list.c
INTERNAL  = $(SRC)/stack/stack_internal.c
TEST_SRC  = $(SRC)/stack/test_stack.c

BIN_ARRAY = test_stack_array
BIN_LIST  = test_stack_list

.PHONY: all array list clean

all: array list

array: $(BIN_ARRAY)
list: $(BIN_LIST)

$(BIN_ARRAY): $(ARRAY_SRC) $(INTERNAL) $(TEST_SRC)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_LIST): $(LIST_SRC) $(INTERNAL) $(TEST_SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(BIN_ARRAY) $(BIN_LIST)
