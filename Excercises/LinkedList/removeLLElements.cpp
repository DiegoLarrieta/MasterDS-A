/*
🔹 LeetCode 203. Remove Linked List Elements
🎯 Enunciado:
Dada una lista enlazada y un valor val, elimina todas las ocurrencias de ese valor en la lista y retorna la lista modificada.

Input:  head = [1,2,6,3,4,5,6], val = 6  
Output: [1,2,3,4,5]

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

        // Metodo para remover elementos con un valor especifico
        Node* removeelements(Node* head, int val){
            // Crear un nuevo nodo temporal que actue como un dummy
            Node* dummy = new Node(-1); // Valor ficticio
            dummy->next = head; // Apunta al inicio de la lista
      
            Node* current = dummy; // Puntero para recorrer la lista que empieza desde dummy

            // Recorrer la lista mientras current no sea NULL
            while(current != NULL && current->next != NULL){
                // Si el siguiente nodo tiene el valor a eliminar 
                if(current->next->data == val){
                    Node* temp = current->next; // Guardar el nodo a eliminar
                    current-> next = current->next->next; // Saltar el nodo duplicado
                    delete temp; // Liberar la memoria del nodo duplicado
                }
                else{
                    current = current->next; // Avanzar al siguiente nodo
                }
            }
            return dummy->next; // Retornar la cabeza de la lista modificada

        }
};