/*

🔄 3. Eliminar duplicados en una lista ordenada
🎯 Si hay nodos consecutivos con el mismo valor, elimina los repetidos.

Input: 1 → 1 → 2 → 3 → 3 → NULL
Output: 1 → 2 → 3 → NULL

🧩 Lógica paso a paso:
📍 Crea un puntero curr que comience en el head de la lista.

🔁 Mientras curr no sea NULL y curr->next tampoco sea NULL:

Compara:
curr->data == curr->next->data

Si son iguales:

Guarda el nodo duplicado en un temporal.

Haz que curr->next salte el duplicado:
curr->next = curr->next->next

Libera la memoria del nodo duplicado si estás en C++.

Si no son iguales:

Avanza curr al siguiente nodo.

Repite hasta llegar al final.

*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    // Constructor para inicializar un nodo
    Node(int value){
        data = value;
        next = NULL;
    }
};

class SinglyLinkedList{
    private:
        // Puntero al primer nodo de la lista
        Node* head;
    
    public:

        // Constructor para inicializar una lista vacia
        SinglyLinkedList(){
            head = NULL;
        }

        // Metodo apra remover duplicados en una lista ordenada

        Node* deleteDuplicates(Node* head){

            // Crear un puntero que apunte a la cabeza 
            Node* curr = head;

            // Mientras curr no sea NULL y curr->next tampoco sea NULL
            while(curr != NULL && curr->next != NULL){
                // Si el valor del nodo actual es igual al siguiente 
                // entonces hay un duplicado
                if(curr->data == curr->next->data){

                    // Guardar el nodo duplicado en un temporal
                    Node* temp = curr->next;

                    // Hacer que curr->next salte el duplicado
                    curr->next = curr->next->next;

                    //Liberar la memoria del nodo duplicado 
                    delete temp;
                }
                else{
                    // Si no son iguales, avanzar al siguiente nodo
                    curr = curr-> next;
                }
            }
            // Retornar la cabeza de la lista sin duplicados
            return head;
        }
};