/*
✅ LeetCode 2 – Add Two Numbers
📌 Problema:
Te dan dos listas enlazadas que representan dos números no negativos.

Cada nodo contiene un solo dígito.

Los dígitos están almacenados en orden inverso: es decir, el número 342 está representado como 2 → 4 → 3.

Debes sumar los dos números y devolver el resultado como una lista enlazada, también en orden inverso.
Input:
l1 = 2 → 4 → 3   // representa 342
l2 = 5 → 6 → 4   // representa 465

Output:
7 → 0 → 8        // representa 807 (342 + 465)

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

class LinkedList{
    private:
        Node* head;

    public:

        LinkedList(){
            head = NULL;
        }
        // O( N + M ) donde N es la longitud de l1 y M es la longitud de l2
        Node* addTwoNumbers(Node* l1, Node* l2) {
            // Paso 1: Crear un nuevo nodo dummy para almacenar el resultado
            Node* dummy = new Node(-1);
            Node* current = dummy; // Puntero para construir la nueva lista

            // Paso 2: Inicializar un carry para manejar la suma de dos dígitos
            int carry = 0;

            // Paso 3: Utilizar 2 punteros uno para cada lista
            Node* pl1 = l1;
            Node* pl2 = l2;

            // Paso 4: Recorrer ambas listas mientras haya nodos en l1 o l2 o carry sea mayor que 0
            while ( pl1 != NULL || pl2 != NULL || carry > 0){
                int sum = carry; // Iniciar la suma con el carry actual

                // Paso 5: Sumar los valores de los nodos actuales y el carry
                if( pl1 != NULL){
                    sum += pl1->data; // Sumar el valor del nodo de l1
                    pl1 = pl1->next;  // Avanzar al siguiente nodo de l1
                }
                if( pl2 != NULL){
                    sum += pl2->data; // Sumar el valor del nodo de l2
                    pl2 = pl2->next;  // Avanzar al siguiente nodo de l2
                }
                // Paso 6: Calcular el nuevo carry y el dígito a añadir al resultado
                carry = sum / 10; // Calcular el nuevo carry. Ej Si sum = 15, entonces carry = 1 (porque 15 ÷ 10 = 1). Se guarda ese 1 para la siguiente suma.
                int digit = sum % 10; // Calcular el dígito a añadir al resultado. Ej. Si sum = 15, entonces digit = 5 (porque 15 % 10 = 5).
                current->next = new Node(digit); // Crear un nuevo nodo con el dígito 

                current = current->next; // Avanzar el puntero current al nuevo nodo
            }
            // Paso 7: Devolver la lista resultante, omitiendo el nodo dummy
            return dummy->next; // Retornar la lista resultante, que comienza después del nodo dummy

        }


};
