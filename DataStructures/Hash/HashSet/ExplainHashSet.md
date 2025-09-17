# 📘 HashSet (unordered_set in C++)

## 🧠 What is a HashSet?
A **HashSet** is a data structure that stores a collection of **unique elements**.  
It is based on a **hash table** that allows fast insertions, deletions, and lookups.  
In C++, the standard implementation is `unordered_set`.

Unlike a HashMap (which stores key–value pairs), a HashSet ONLY STORES **keys**, ensuring that no duplicates exist.

---

## ⚡ Time Complexity

| Operation       | Average Case | Worst Case* |
|-----------------|--------------|-------------|
| Insert          | O(1)         | O(n)        |
| Search / Lookup | O(1)         | O(n)        |
| Delete          | O(1)         | O(n)        |

> *Worst case happens when many elements collide in the same bucket, degrading performance to linear time.*

---

## 📌 Key Characteristics
- Stores **only keys** (no values).
- Keys are **unique**: duplicate elements are automatically ignored.
- Keys are **unordered**: order is not preserved.
- Uses a **hash function** to determine the storage bucket.

---

## ✅ Benefits
- **Fast existence check**: ideal for membership testing in O(1) average time.
- Automatically prevents **duplicates**.
- Efficient for **set operations** like union, intersection, and difference.
- Provides cleaner logic when only keys are relevant (no need for values like in HashMap).

---

## 🚨 Limitations
- Keys are unordered (if ordering is required, use `set` instead of `unordered_set`).
- Performance depends on the quality of the hash function (poor hashing → collisions).
- Slightly higher **memory overhead** compared to arrays or vectors.

---

## 📂 Common Use Cases
- **Checking membership**: determining if an element exists in a collection.
- **Removing duplicates**: storing only unique items from a list.
- **Set operations**: union, intersection, difference of two sets.
- **Graph and algorithm problems**: keeping track of visited nodes in BFS/DFS.
- **Sliding window problems**: checking if a substring or subarray has repeating elements.

---

## 🎯 Summary
A **HashSet** is the best choice when:
- You need to **store only unique items**.
- You need **fast lookups** to check if an element exists.
- You want to handle problems involving **duplicates, membership, or visited tracking**.

It is widely used in interview problems related to arrays, strings, and graphs where uniqueness and quick existence checks are required.
