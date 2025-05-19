# Queues: Overview, Complexity, and Use Cases

## **What is a Queue?**
A **queue** is a linear data structure that follows the **First In, First Out (FIFO)** principle. This means that the first element added to the queue is the first one to be removed, similar to a line of people waiting for a service.

Queues can be implemented using arrays, linked lists, or dynamic memory structures, and they are widely used in various algorithms and real-world applications.

- Los elementos se **agregan al final (enqueue)** y se **eliminan del frente (dequeue)**.


---

## **Complexity of Operations in Queues**


| Operación     | Descripción                                      | Complejidad |
|---------------|--------------------------------------------------|-------------|
| `enqueue(x)`  | Inserta el elemento `x` al final de la cola      | O(1)        |
| `dequeue()`   | Elimina el primer elemento de la cola            | O(1)        |
| `front()`     | Devuelve el primer elemento sin eliminarlo       | O(1)        |
| `isEmpty()`   | Verifica si la cola está vacía                   | O(1)        |
| `size()`      | Retorna el número de elementos en la cola        | O(1)        |

---

## **Benefits of Using Queues**
1. **FIFO Order**: Queues are ideal for scenarios where elements need to be processed in the order they arrive.
2. **Efficient Operations**: Adding and removing elements from a queue are efficient operations with constant time complexity.
3. **Simple Implementation**: Queues are easy to implement using arrays or linked lists.

---

## **When to Use Queues**
1. **Task Scheduling**: Queues are used in operating systems for task scheduling (e.g., CPU scheduling, I/O scheduling).
2. **Breadth-First Search (BFS)**: Queues are used in graph traversal algorithms like BFS.
3. **Data Streaming**: Queues are used to manage data streams in real-time systems.
4. **Order Processing**: Queues are used in scenarios like ticket booking systems or customer service lines.

---

## **Use Cases for Queues**
1. **Print Queue**: Managing print jobs in a printer.
2. **Task Scheduling**: Managing tasks in operating systems or thread pools.
3. **Breadth-First Search**: Traversing graphs or trees level by level.
4. **Data Buffers**: Managing data streams in real-time applications.
5. **Messaging Systems**: Queues are used in message brokers like RabbitMQ or Kafka.

---

