# HashMap (unordered_map in C++)

## 🧠 What is a HashMap?
A **HashMap** is a data structure that stores elements in **key-value pairs**.  
It uses a **hash function** to map each key to a specific bucket, allowing efficient access to values based on their keys.  
In C++, the standard implementation is `unordered_map`.

---

##  Time Complexity

| Operation       | Average Case | Worst Case* |
|-----------------|--------------|-------------|
| Insert          | O(1)         | O(n)        |
| Search / Lookup | O(1)         | O(n)        |
| Delete          | O(1)         | O(n)        |

> *The worst case occurs when multiple keys are mapped to the same bucket (hash collision), which can degrade performance to linear time.*

---

##  Key Characteristics
- Stores data as **key → value** pairs.
- Keys are **unique** (no duplicates).
- Keys are **unordered** (the order is not guaranteed).
- Requires a **hash function** to map keys efficiently.

---

##  Benefits
- **Fast access** to elements (average O(1)).
- **Flexible key types**: can use integers, strings, or even custom objects (with custom hash functions).
- Ideal for problems requiring:
  - **Counting** (frequency maps).
  - **Existence checks**.
  - **Key-value associations** (like dictionaries).

---

##  Limitations
- Does **not maintain order** of keys (if you need sorted keys, use `map` instead).
- Hash collisions can reduce performance.
- Slightly more **memory overhead** compared to arrays or lists.

---

##  Common Use Cases
- **Counting frequencies**: e.g., character counts in a string, word counts in a document.
- **Checking existence quickly**: e.g., detecting duplicates in an array.
- **Mapping identifiers**: e.g., usernames to IDs, product names to prices.
- **Caching and memoization**: storing precomputed results in dynamic programming.

---

## 🎯 Summary
A **HashMap** is your go-to data structure when you need:
- **Constant-time access** to elements.
- **Efficient key–value mappings**.
- **Flexible and dynamic storage** for problems involving frequency, lookup, or caching.

It is one of the most powerful tools in interviews, especially for problems involving counting, grouping, and fast searching.
