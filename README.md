# Missionaries and Cannibals Problem

This project solves the **Missionaries and Cannibals problem** using different **Artificial Intelligence search algorithms** implemented in **C**.

The program compares multiple search methods and prints the **solution path, expanded nodes, and execution time**.

---

# Problem Description

There are:

* **3 Missionaries**
* **3 Cannibals**
* **1 Boat**

All start on the **left side of a river**.

The goal is to move everyone safely to the **right side**.

---

# Constraints

The following rules must always be satisfied:

* The boat can carry **maximum 2 people**.
* The boat must carry **at least 1 person**.
* If cannibals outnumber missionaries on either side, the missionaries are eaten.
* The boat must be on the same side as the people crossing.

---

# Initial State

```
(M=3, C=3, Boat=Left)
```

# Goal State

```
(M=0, C=0, Boat=Right)
```

---

# Search Algorithms Used

The program implements four search algorithms.

## Breadth First Search (BFS)

* Explores states **level by level**
* Uses a **queue**
* Guarantees the **shortest solution**

## Depth First Search (DFS)

* Explores **deep nodes first**
* Uses a **stack**
* Uses less memory but may not give the shortest path

## Depth Limited Search (DLS)

* A DFS with a **maximum depth limit**
* Prevents searching infinitely deep

## Iterative Deepening DFS (IDDFS)

* Runs **Depth Limited Search repeatedly**
* Depth limit increases each time
* Combines advantages of BFS and DFS

---

# State Representation

Each state is stored using a structure:

```c
typedef struct {
    int m, c, boat;
    int depth, cost;
    int parent;
} Node;
```

Where:

* **m** → missionaries on left bank
* **c** → cannibals on left bank
* **boat** → boat position
* **depth** → search tree depth

---

# How the Program Works

1. Start from the initial state.
2. Generate all valid next states.
3. Check constraints.
4. Continue searching until the goal state is found.

---

# Output

The program prints:

* The solution path
* Number of expanded nodes
* Execution time for each search algorithm

---

