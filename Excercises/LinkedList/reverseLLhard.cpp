/*
92. Reverse Linked List II
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
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
        SinglyLinkedList(){
            head = NULL;
        }

        Node* reverseBetween(Node* head, int left, int right) {

            // Nodo dummy para facilitar la manipulación
            Node* dummy = new Node(-1);
            dummy->next = head;
            Node* prev = dummy;

            // Avanzar prev hasta el nodo antes de 'left'
            for(int i = 0; i < left - 1; i++){
                prev = prev->next;
            }
            // Nodo 'curr' apunta al primer nodo a invertir
            Node* curr = prev->next;

            // Invertir los nodos entre left y right

            for(int i = 0; i < right - left; i++){
                Node* temp = curr->next; // Guardar el siguiente nodo
                curr->next = temp->next; // Desconectar el nodo actual
                temp->next = prev->next; // Conectar el nodo temporal al inicio de la sección invertida
                prev->next = temp; // Conectar el nodo temporal al final de la sección invertida
            }
            // Retornar la nueva cabeza de la lista
            return dummy->next;


        }

};