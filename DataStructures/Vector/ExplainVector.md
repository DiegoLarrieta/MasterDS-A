# Vectors in C++

## **What is a Vector?**
A **vector** in C++ is a dynamic array provided by the Standard Template Library (STL). Unlike regular arrays, vectors can grow or shrink in size dynamically as elements are added or removed. Vectors are part of the `<vector>` header.

---

## **Key Features of Vectors**
1. **Dynamic Size**: Vectors automatically resize themselves when elements are added or removed.
2. **Contiguous Memory**: Elements are stored in contiguous memory locations, similar to arrays.
3. **Random Access**: Provides constant-time access to elements using an index.
4. **Built-in Functions**: Vectors come with a variety of built-in functions for easy manipulation.

---

## **Basic Operations**
| Operation        | Time Complexity | Description                                                                 |
|------------------|-----------------|-----------------------------------------------------------------------------|
| **Accessing**    | O(1)            | Direct access to elements using an index.                                   |
| **Inserting**    | O(1) (at end) / O(n) | Inserting at the end is amortized O(1); inserting in the middle requires shifting. |
| **Deleting**     | O(1) (at end) / O(n) | Deleting from the end is O(1); deleting in the middle requires shifting.   |
| **Searching**    | O(n)            | Linear search is required unless the vector is sorted.                     |

---

## **Advantages of Vectors**
1. **Dynamic Resizing**: No need to manually manage memory or resize arrays.
2. **Ease of Use**: Provides built-in functions like `push_back`, `pop_back`, `size`, and `clear`.
3. **Random Access**: Allows fast access to elements using indices.
4. **STL Integration**: Works seamlessly with other STL algorithms and containers.

---

## **Commonly Used Functions**
| Function         | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| `push_back(x)`   | Adds an element `x` to the end of the vector.                              |
| `pop_back()`     | Removes the last element of the vector.                                    |
| `size()`         | Returns the number of elements in the vector.                              |
| `clear()`        | Removes all elements from the vector.                                      |
| `at(index)`      | Returns the element at the specified index (with bounds checking).         |
| `front()`        | Returns the first element of the vector.                                   |
| `back()`         | Returns the last element of the vector.                                    |
| `empty()`        | Checks if the vector is empty.                                             |
| `insert(pos, x)` | Inserts an element `x` at the specified position `pos`.                    |
| `erase(pos)`     | Removes the element at the specified position `pos`.                      |

---

## **When to Use Vectors**
1. **Dynamic Data**: When the size of the data is not known in advance or changes frequently.
2. **Random Access**: When you need fast access to elements using indices.
3. **STL Algorithms**: When you want to leverage STL algorithms like `sort`, `find`, etc.
4. **Ease of Use**: When you want a simpler alternative to manually managing arrays.

---

