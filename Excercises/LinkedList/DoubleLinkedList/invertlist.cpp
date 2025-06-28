/*

🔁 5. Invertir una lista doblemente enlazada
🎯 Objetivo: Invierte el orden de los nodos de la DLL. El head se convierte en el tail y viceversa.

🧪 Ejemplo:
Input: 1 <-> 2 <-> 3 <-> 4
Output: 4 <-> 3 <-> 2 <-> 1

*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    };
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;

    public:

    // Metodo para invertir la lista

    void inverList(){
        if(head == NULL || head->next == NULL){
            cout << "La lista está vacía o tiene un solo nodo, no se puede invertir." << endl;
            return; // Si la lista está vacía o tiene un solo nodo, no hay nada que invertir
        }
        Node* current = head; // Puntero para recorrer la lista
        Node* next = NULL; // Puntero temporal para almacenar el siguiente nodo

        // Recorremos la lista y vamos intercambiando los punteros next y prev
        while(current != NULL){
            next = current->next;

            current->next = current->prev;

            current->prev = next;
            // Mover al siguiente nodo
            current = next;
        }
        // Al finalizar, intercambiamos head y tail
        Node* temp = head; // Guardamos la cabeza actual
        head = tail; // Actualizamos la cabeza a ser la cola
        tail = temp; // Actualizamos la cola a ser la cabeza
    }
};