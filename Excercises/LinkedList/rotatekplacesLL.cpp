/*

🔄 61. Rotar Lista Ligada (Rotate List)
🎯 Objetivo:
Dada una lista enlazada y un número entero k, rota la lista hacia la derecha k veces.

📥 Input:

head = [1,2,3,4,5], k = 2

📤 Output:

[4,5,1,2,3]

// Proceso
// 5 -> 1 -> 2 -> 3 -> 4
// 4 -> 5 -> 1 -> 2 -> 3
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
        // O(N)
        Node* rotateRight(Node* head, int k) {
            // Paso 1: Si la lista está vacía o tiene un solo nodo, no hay nada que rotar
            if (head == NULL || head->next == NULL || k <= 0) {
                return head;
            }
            // Paso 2: Calcular la longitud de la lista
            int length = 1; // Iniciar con 1 porque contamos el nodo head
            Node* tail = head; // Puntero para encontrar el último nodo
            while(tail->next != NULL){
                tail = tail->next; // Avanzar al siguiente nodo
                length++; // Incrementar la longitud
            }


            // Paso 3: Conectamos el ultimo nodo al head para formar un ciclo
            tail->next = head;

            // Paso 4: Calcular el número de rotaciones efectivas, recuerda que % da el residuo 
            // Lo de las rotaciones efectivas es para evitar rotaciones innecesarias, por ejemplo si k es mayor que la longitud de la lista
            // k = k % length = 2 % 5 = 2
            k = k % length; 

            // Paso 5: Encontrar el nuevo tail de la lista y esto nos dira donde cortar la lista y cual es el nuevo head
            Node* newTail = head; // Empezar desde la cabeza
            //length - k - 1 , quiere decir que el nodo en la posicion 2 empezando desde 0, sera el nuevo tail, y luego ->next sera el nuevo head
            for (int i = 0; i < length - k - 1; i++) { // length - k - 1 = 5 - 2 - 1 = 2
                newTail = newTail->next; // Avanzar hasta el nuevo tail
            }
            // Paso 6: El nuevo head es el siguiente del nuevo tail y rompemos el ciclo 
            Node* newHead = newTail->next; // El nuevo head es el siguiente del nuevo tail
            newTail->next = NULL; // Romper el ciclo
            return newHead; // Devolver el nuevo head
        }
};