# C Data Structures

## Overview

This repository contains a curated implementation of core data structures in **C**, developed with a strong focus on **memory safety**, **representation invariants**, and **performance trade-offs**.

---

## Implemented Modules

Each module is implemented as an independent component with its own header, implementation, and tests.

- Stack ADT
  - Array-based stack
  - Linked-list-based stack

- Queue ADT
  - Array-based circular buffer queue
  - Linked-list-based queue


---

## Design Principles

The following principles guided the implementation:

* **Explicit invariants**: each data structure defines and enforces representation invariants using assertions.
* **Clear ownership rules**: allocation and deallocation responsibilities are well-defined.
* **Modularity**: each structure can be used independently as a small library.
* **Defensive programming**: invalid states are detected early rather than ignored.

More details can be found in the `docs/` directory.

---

## Memory Safety & Debugging

All modules were tested using:

* `valgrind` for leak detection and invalid memory access
* `assert` for invariant checking
* `gdb` for debugging non-trivial errors

Known pitfalls (such as double frees, dangling pointers, and invalid reads) are documented where relevant.

---

## What This Project Is Not

* This is **not** meant to be a full-featured production library.

The emphasis is on correctness, clarity, and reasoning rather than completeness or performance tuning beyond educational scope.

---

## Build & Usage

A simple `Makefile` is provided to compile and test each data structure
(Stack and Queue), with both array-based and list-based implementations.

```bash
make
```

This builds the following test binaries:

    test_stack_array

    test_stack_list

    test_queue_array

    test_queue_list

Each data structure can also be built independently:

```bash
make stack
make queue
```

To clean all generated binaries:

```bash
make clean
```
---

## Background

The original versions of these implementations were developed as part of undergraduate coursework in Algorithms and Data Structures. They were later revised, cleaned up, and reorganized.

---

## Author

Nicolás Fernández Montenegro
