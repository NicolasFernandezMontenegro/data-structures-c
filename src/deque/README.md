# Deque ADT

## Overview

This module implements a double-ended queue (deque) abstraction with two
interchangeable representations:

- Doubly-linked-list-based deque
- Array-based circular buffer deque

Both implementations expose the same public interface and are validated
using a shared test suite.

--- 

## Design Notes

- The array-based implementation uses a circular buffer with dynamic resizing.
- Insertions and removals at both ends run in O(1) time.
- The list-based implementation maintains explicit front and back pointers.
- Representation invariants are enforced using assertions.
- All memory management responsibilities are explicit.

---

## Testing

Both implementations are validated using the same test suite:

- Push and pop operations at both ends
- Edge cases (empty, singleton)
- Mixed front/back operations

All tests pass under `valgrind` with no memory leaks or invalid accesses.