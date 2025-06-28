/*
🎯 5. Encontrar el valor medio de la lista
🎯 Devuelve el valor que se encuentra en el medio de la lista.

Input: 1 → 2 → 3 → 4 → 5
Output: 3
📌 Si hay dos medios, devuelve el segundo.


*/

#include <iostream>
using namespace std;

// Paso 1 hacer la estructura de un nodo
struct Node{
    int data;
    Node* next;

    // Constructor para inicializar un nodo
    Node(int value){
        data = value;
        next = NULL;
    }
};

// Paso 2: Crear la clase de la lista enlazada
class SinglyLinkedList{
    private:
        Node* head;
    
    public:
        // Constructor para inicializar una lista vacia
        SinglyLinkedList(){
            head = NULL;
        }

        // Método para encontrar el valor medio de la lista
        /* 
        Aqui es utilizar dos punteros uno lento y otro rapido
        El puntero lento se mueve un paso a la vez, mientras que el puntero rápido se mueve dos pasos a la vez.
        */

       int findMiddleNode(){
            // Si la lista está vacía, no hay medio
            if(head == NULL){
                return -1;
            }

            // Inicializar los punteros lento y rápido
            Node* slow = head; // Puntero lento
            Node* fast = head; // Puntero rápido

            // Mover los punteros hasta que el puntero rápido llegue al final
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;          // Mover lento un paso
                fast = fast->next->next;   // Mover rápido dos pasos
            }
            // Cuando el puntero lento alcanza el medio, devolver su valor
            return slow->data; // Devolver el valor del nodo medio
       }
};