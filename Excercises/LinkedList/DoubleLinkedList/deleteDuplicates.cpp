/*

🧹 6. Eliminar nodos duplicados (lista ordenada)
🎯 Objetivo: Si hay valores repetidos consecutivos en la lista, elimina los duplicados.

🧪 Ejemplo:
Input: 1 <-> 1 <-> 2 <-> 3 <-> 3
Output: 1 <-> 2 <-> 3


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

        void deleteDuplicates(){
            if(head == NULL || head->next == NULL){
                cout << "La lista está vacía o tiene un solo nodo, no hay duplicados." << endl;
                return; // Si la lista está vacía o tiene un solo nodo, no hay duplicados
            }
            Node* current = head;
            while(current != NULL){
                // Puntero al siguiente nodo
                Node* nextNode = current->next;

                // Mientras el siguiente nodo no sea nulo y tenga el mismo valor que el nodo actual
                while(nextNode != NULL && nextNode->data == current->data){
                    Node* duplicateNode = nextNode; // Guardar el nodo duplicado
                    nextNode = nextNode->next; // Mover al sigueinte nodo

                    // Si el nodo duplicado es el ultimo nodo, actualizar el tail
                    if(duplicateNode == tail){
                        tail = current; // Actualizar el tail al nodo actual
                    }
                    // Liberar memoria del nodo duplicado
                    delete duplicateNode;
                }
                // Conectar el nodo actual al siguiente nodo no duplicado
                current->next = nextNode;
                if(nextNode != NULL){
                    nextNode->prev = current; // Actualizar el puntero previo del siguiente nodo
                }
                current = nextNode; // Mover al siguiente nodo
            }
        }
};