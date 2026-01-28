# Queue ADT

## Overview

This module implements a FIFO queue abstraction with two interchangeable
representations:

- Linked-list-based queue
- Array-based circular buffer queue

Both implementations expose the same public interface and are validated
using a shared test suite.

---

## Design Notes

- The array-based implementation uses a circular buffer with dynamic resizing.
- The list-based implementation maintains explicit front and back pointers.
- Representation invariants are enforced using assertions.
- All memory management responsibilities are explicit.

---

## Testing

Both implementations are validated using the same test suite:

- FIFO ordering
- Edge cases (empty, singleton)
- Interleaved enqueue and dequeue operations

All tests pass under `valgrind` with no memory leaks or invalid accesses.
