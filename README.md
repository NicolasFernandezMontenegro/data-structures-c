# C Data Structures

## Overview

This repository contains a curated implementation of core data structures in **C**, developed with a strong focus on **memory safety**, **representation invariants**, and **performance trade-offs**.

---

## Implemented Modules

Each module is implemented as an independent component with its own header, implementation, and tests.

### Included data structures

* **Stack**

  * Array-based implementation
  * Linked-list-based implementation
  * Comparison of memory and performance trade-offs

* **Queue**

  * Efficient O(1) enqueue and dequeue
  * Edge-case handling for empty and singleton queues

* **Binary Search Tree (BST)**

  * Insert, search, and removal
  * Non-trivial deletion cases
  * Explicit representation invariants

* **Dictionary (Key-Value Store)**

  * Built on top of a BST
  * Demonstrates code reuse and abstraction

* **String ADT**

  * Manual memory management
  * Copy, comparison, and ordering operations

* **Tower of Hanoi**

  * Recursive algorithm implementation
  * Used as a case study for debugging and memory analysis

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

A simple `Makefile` is provided to compile individual modules and run basic tests.

```bash
make
```

Each module can be compiled independently.

---

## Background

The original versions of these implementations were developed as part of undergraduate coursework in Algorithms and Data Structures. They were later revised, cleaned up, and reorganized.

---

## Author

Nicolás Fernández Montenegro
