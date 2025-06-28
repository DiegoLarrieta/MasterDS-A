/*
🧩 Problema: Partition List LeetCode 86
📌 Enunciado resumido:

Dada una lista enlazada y un valor x, reorganiza la lista de modo que:

Todos los nodos con valores menores que x estén antes

Todos los nodos con valores mayores o iguales a x estén después

⚠️ ¡Mantén el orden relativo original de cada grupo!

Ejemplo:

Input:  1 → 4 → 3 → 2 → 5 → 2,  x = 3  
Output: 1 → 2 → 2 → 4 → 3 → 5

Los menores que 3: 1, 2, 2 → van al principio (en orden)

Los mayores o iguales que 3: 4, 3, 5 → van después (también en orden)
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class SinglyLinkedList{
    private:
        Node* head;

    public:
        SinglyLinkedList(){
            head = NULL;
        }

        Node* partition(Node* head, int x) {
            // Paso 1: Crear dos listas para los nodos menores y mayores o iguales a x
            Node* lessHead = new Node(-1); // Lista para nodos menores
            Node* greaterHead = new Node(-1); // Lista para nodos mayores o iguales

            // Paso 2: Punteros para las listas
            Node* less = lessHead; // Puntero para la lista de menores
            Node* greater = greaterHead; // Puntero para la lista de mayores o iguales
            Node* current = head; // Puntero para recorrer la lista original

            // Paso 3: Recorrer la lista original
            while(current != NULL){
                // Si el valor es < x ( menor ) lo agregemos a la lista de menores
                if(current->data < x){
                    less->next = current; // Conectar el nodo actual a la lista de menores
                    less = less->next; // Movemos el puntero de la lista de menores
                }else{
                    // Si el valor es >= x ( mayor o igual ) lo agregamos a la lista de mayores o iguales
                    greater->next = current; // Conectar el nodo actual a la lista de mayores o iguales
                    greater = greater->next; // Movemos el puntero de la lista de mayores o iguales
                }
                current = current->next; // Avanzar al siguiente nodo en la lista original
            }
            // Paso 4: Conectar las dos listas
            greater->next = NULL; // Terminar la lista de mayores o iguales
            less->next = greaterHead->next; // Conectar la lista de menores con la de mayores o iguales

            // Paso 5: Retornar la nueva lista particionada
            Node* newHead = lessHead->next; // La nueva cabeza es el primer nodo de la lista de menores
            delete lessHead; // Liberar memoria del nodo ficticio de la lista de menores
            delete greaterHead; // Liberar memoria del nodo ficticio de la lista de mayores o iguales
            return newHead; // Retornar la nueva cabeza de la lista particionada

        }
};
