/*
🔗 Problema: Merge Two Sorted Linked Lists
📘 (LeetCode 21: Merge Two Sorted Lists)

🎯 Enunciado:
Te dan dos listas enlazadas ordenadas de forma ascendente.
Tu tarea es combinarlas en una sola lista también ordenada y devolver su head.

Input:
List1: 1 → 2 → 4  
List2: 1 → 3 → 5

Output:
Merged: 1 → 1 → 2 → 3 → 4 → 5

*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    //Constructor 
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

        Node* mergeTwoLists(Node* list1, Node* list2) {
            // Crear un nodo dummy para facilitar la construcción
            Node* dummy = new Node(-1);

            // Puntero para construir la nueva lista
            Node* tail = dummy;

            // Mientras ambas listas tengan nodos
            while (list1 != NULL && list2 != NULL) {
                // Si el nodo de list1 es menor que el de list2, lo añadimos a la lista resultante
                if (list1->data <= list2->data) {
                    tail->next = list1;// Añadir el nodo de list1
                    list1 = list1->next;// Avanzar al siguiente nodo de list1
                }
                // Si el nodo de list2 es menor o igual, lo añadimos a la lista resultante
                else {
                    tail->next = list2;// Añadir el nodo de list2
                    list2 = list2->next;// Avanzar al siguiente nodo de list2
                }
                // Avanzar el puntero taili-t
                tail = tail->next;
            }

            // Conectar el resto de la lista que no ha terminado si alguna de las listas aún tiene nodos
            // Si list1 aún tiene nodos, los añadimos
            // Si list2 aún tiene nodos, los añadimos
            if (list1 != NULL) {
                tail->next = list1;
            } else {
                tail->next = list2;
            }

            // Necesito eliminar el nodo dummy para no devolverlo
            Node* mergedHead = dummy->next; // Guardar el primer nodo real
            delete dummy; // Liberar memoria del nodo dummy
            // Retornar el primer nodo real de la lista combinada
            return dummy->next; // Retornar el primer nodo real
        }

};