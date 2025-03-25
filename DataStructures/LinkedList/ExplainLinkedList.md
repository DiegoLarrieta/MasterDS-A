# Linked Lists: Overview, Types, Complexity, and Use Cases

## **What is a Linked List?**
A **linked list** is a linear data structure where elements, called **nodes**, are connected using pointers. Each node contains:
1. **Data**: The value stored in the node.
2. **Pointer**: A reference to the next node in the sequence (or previous node in some cases).

Unlike arrays, linked lists do not store elements in contiguous memory locations. Instead, each node is dynamically allocated and linked together.

---

## **Types of Linked Lists**
### 1. **Singly Linked List (SLL)**
- Each node contains:
  - **Data**: The value of the node.
  - **Next Pointer**: A reference to the next node in the list.
- The last node's `next` pointer is set to `NULL`, indicating the end of the list.

#### **Example Structure**:
- [Data|Next] -> [Data|Next] -> [Data|Next] -> NULL


#### **Use Cases**:
- When you only need to traverse the list in one direction.
- Suitable for simple operations like stack implementation.

---

### 2. **Doubly Linked List (DLL)**
- Each node contains:
  - **Data**: The value of the node.
  - **Next Pointer**: A reference to the next node.
  - **Previous Pointer**: A reference to the previous node.
- The first node's `prev` pointer is `NULL`, and the last node's `next` pointer is `NULL`.

#### **Example Structure**:
- NULL <- [Prev|Data|Next] <-> [Prev|Data|Next] <-> [Prev|Data|Next] -> NULL


#### **Use Cases**:
- When you need to traverse the list in both directions.
- Useful for implementing complex data structures like deques or LRU caches.

---

## **Complexity of Operations**

| Operation   | Singly Linked List (SLL) | Doubly Linked List (DLL) | Explanation                                                                 |
|-------------|---------------------------|---------------------------|-----------------------------------------------------------------------------|
| **Accessing** | O(n)                     | O(n)                     | Traversal is required to access a specific node.                           |
| **Inserting** | O(1) (at head) / O(n)    | O(1) (at head) / O(n)    | Inserting at the head is O(1); inserting at a specific position requires traversal. |
| **Deleting**  | O(1) (at head) / O(n)    | O(1) (at head) / O(n)    | Deleting at the head is O(1); deleting a specific node requires traversal.  |
| **Searching** | O(n)                     | O(n)                     | Linear search is required to find a specific node.                         |

---

## **Benefits of Linked Lists**
1. **Dynamic Size**: Unlike arrays, linked lists can grow or shrink dynamically without the need for resizing or reallocation.
2. **Efficient Insertions/Deletions**: Adding or removing elements at the beginning or middle is faster compared to arrays (no shifting required).
3. **Memory Utilization**: Memory is allocated as needed, avoiding wasted space.

---

## **When to Use Linked Lists**
### **Singly Linked List (SLL)**
- When memory usage is a concern (less overhead compared to DLL).
- When you only need to traverse the list in one direction.
- For implementing stacks or simple queues.

### **Doubly Linked List (DLL)**
- When you need bidirectional traversal.
- When frequent insertions and deletions are required at both ends or in the middle.
- For implementing more complex data structures like deques, LRU caches, or navigation systems.

---

## **Summary**
Linked lists are a versatile data structure that provide flexibility in memory management and efficient insertions/deletions. However, they have slower access times compared to arrays due to the need for traversal. Choosing between a singly or doubly linked list depends on the specific requirements of your application.