/*

📍 4. Detectar si hay un ciclo en la lista
🎯 Devuelve true si la lista contiene un ciclo (un nodo apunta a un nodo previo).

📌 Usa la técnica de tortuga y liebre (slow & fast pointers).
(💡 Aún sin necesidad de resolverlo, entender esta técnica te prepara para el futuro).


*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor para inicializar un nodo
    Node(int value) {
        data = value;
        next = NULL;
    }
};
class SinglyLinkedList {
    private:
        Node* head; // Puntero al primer nodo de la lista
    public:
        // Constructor para inicializar una lista vacia
        SinglyLinkedList(){
            head = NULL;
        }

        // Método para detectar si hay un ciclo en la lista
        bool hasCycle() {
            Node* slow = head; // Puntero lento
            Node* fast = head; // Puntero rápido

            // Mientras el puntero rápido y su siguiente no sean nulos
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;          // Mover lento un paso
                fast = fast->next->next;   // Mover rápido dos pasos

                if (slow == fast) {         // Si se encuentran, hay un ciclo
                    return true;
                }
            }
            return false; // Si no se encuentran, no hay ciclo
        }
};