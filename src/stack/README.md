# Stack

This module provides a LIFO stack ADT with two interchangeable
implementations:

- Array-based (dynamic resizing, amortized O(1) push)
- Linked-list-based (O(1) push/pop, no realloc)

Both implementations:
- Enforce representation invariants via assertions
- Share the same public interface (`stack.h`)
- Are tested with the same test suite
- Are verified with valgrind (no leaks)

