/*

🧠 1. Obtener el k-ésimo nodo desde el final
🎯 Devuelve el valor del nodo que está a k posiciones desde el final de la lista.

Input: 1 → 2 → 3 → 4 → 5, k = 2
Output: 4

✅

💡 ¿Cómo resolverlo?
La forma más eficiente es usando la técnica de dos punteros:

🪄 Paso a paso (técnica de "ventana deslizante"):
Crea dos punteros: first y second, ambos apuntan a head.

Mueve el first k pasos hacia adelante.

Si no puedes avanzar k pasos (porque la lista es más corta), retornas NULL.

Luego, mueves ambos punteros (first y second) uno a uno hasta que first llegue al final.

En ese momento, el puntero second estará en el nodo k-ésimo desde el final.



*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next; // Puntero al siguiente nodo

    // Constructor para inicializar un nodo
    Node(int value){
        data = value;
        next = NULL;
    }
};

class SinglyLinkedList{
    private:
        Node* head; // Puntero al primer nodo de la lista
    
    public:
        // Constructor para inicializar una lista vacia
        SinglyLinkedList(){
            head = NULL;
        }

        // Método para insertar un nodo al inicio
        void insertAtHead(int value){
            Node* newNode = new Node(value); // Crear un nuevo nodo
            newNode ->next = head; // Apuntar al nodo actual de la cabeza
            head = newNode; // Actualizar la cabeza

        }

        void getKthFromEnd(int k){
            // Primer puntero 
            Node* first = head;

            // Segundo puntero
            Node* second = head;

            // Mover el primer puntero k pasos hacia adelante
            for(int i = 0; i < k; i++){
                if(first == NULL){
                    cout << "La lista es mas corta que k." << endl;
                    return; // Si no se puede avanzar k pasos, retornar
                }
                first = first->next; // Mover el primer puntero
            }
            // Mover ambos punteros hasta que el primer llegue al final
            while(first != NULL){
                first = first->next; // Mover el primer puntero
                second = second->next; // Mover el segundo puntero
            }
            // En este punto, el segundo puntero está en el k-ésimo nodo desde el final
            if(second != NULL){
                cout << "El k-ésimo nodo desde el final es: " << second->data << endl;
            } else {
                cout << "No se encontró el k-ésimo nodo desde el final." << endl;
            }
        }
};

int main(){
    SinglyLinkedList list;

    // Insertar elementos en la lista
    list.insertAtHead(1); // Lista: 1
    list.insertAtHead(2); // Lista: 2 -> 1
    list.insertAtHead(3); // Lista: 3 -> 2 -> 1
    list.insertAtHead(4); // Lista: 4 -> 3 -> 2 -> 1
    list.insertAtHead(5); // Lista: 5 -> 4 -> 3 -> 2 -> 1

    // Obtener el k-ésimo nodo desde el final
    int k = 2;
    list.getKthFromEnd(k); // Debería imprimir "El k-ésimo nodo desde el final es: 4"

    return 0;
}

