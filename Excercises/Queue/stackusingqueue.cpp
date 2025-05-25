/*
🔹 1. Implement Stack using Queues
📘 LeetCode 225
Implementa una pila (stack) usando solo una o dos colas (queue).

Aprendes: simular LIFO usando FIFO

Técnicas: dos queue, o una y rotar los elementos
Queue
1 2 3 4 5 

Stack
5
4
3
2
1
*/

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
        // Constructor vacío
    }

    // Método para agregar un elemento a la pila
    void push(int x) {
        q.push(x);
        int size = q.size();

        // Rotamos los elementos anteriores detrás del nuevo
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
