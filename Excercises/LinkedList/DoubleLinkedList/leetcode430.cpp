/*

🧩 Problema: Flatten a Multilevel Doubly Linked List
Tienes una lista doblemente enlazada (DLL) en la que algunos nodos tienen un puntero child que apunta a otra lista doblemente enlazada.
Esa lista child también puede tener su propio child, formando una estructura en árbol de DLLs.

Ejemplo:
1 - 2 - 3 - 4 - 5 - 6
        |
        7 - 8 - 9 - 10
            |
            11 - 12

Salida esperada
1 - 2 - 3 - 7 - 8 - 11 - 12 - 9 - 10 - 4 - 5 - 6



*/
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
        child = NULL;
    }
};
class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        // Metodo para aplanar la lista
        Node* flatten(Node* head) {
            // Default si la lista esta vacia retornamos null
            if (head == NULL) {
                return NULL;
            }
            // 1. Crear un puntero para recorrer la lista
            Node* current = head; 
            Node* tail = head; // Puntero para encontrar el tail

            // 2. Recorremos la lista principal
            while(current != NULL){
                // 3. Si el nodo actual tiene un child, lo aplanamos
                if(current->child != NULL){

                    // Guardamos el siguiente nodo
                    Node* nextNode = current->next;
                    // Aplanamos la lista child
                    Node* childHead = flatten(current->child);

                    // Conectar el child con el current
                    current->next = childHead; // Conectar el nodo actual al head de la lista child
                    childHead->prev = current; // Actualizar el puntero previo del head de la lista child

                    // 4. Conectamos el tail de la lista child al siguiente nodo
                    Node* childTail = childHead;
                    while(childTail->next != NULL) {
                        childTail = childTail->next; // Encontrar el tail de la lista child
                    }
                    // Conectar el tail de la lista child al siguiente nodo
                    childTail->next = nextNode;
                    if (nextNode != NULL) {
                        nextNode->prev = childTail; // Actualizar el puntero previo del siguiente nodo
                    }
                    // 5. Limpiar el child del nodo actual
                    current->child = NULL; // Limpiar el child del nodo actual

                    current = nextNode; // Avanzar al siguiente nodo
                } else {
                    // 6. Si no hay child, simplemente avanzamos al siguiente nodo
                    tail = current; // Actualizar el tail
                    current = current->next; // Avanzar al siguiente nodo
                }
            }
            // 7. Retornar el head de la lista aplanada
            return head; // Retornar el head de la lista aplanada
        }
};