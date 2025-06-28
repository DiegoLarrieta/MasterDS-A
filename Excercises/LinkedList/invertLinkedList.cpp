/*
LEETCODE 206
🔁 2. Invertir una Linked List
🎯 Invierte todos los nodos de la lista.

Input: 1 → 2 → 3 → 4 → NULL
Output: 4 → 3 → 2 → 1 → NULL

📌 Pista: Necesitas 3 punteros: prev, curr, next.

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

class InvertedLinkedList{
    private:
        Node* head;
        
    public:
        InvertedLinkedList(){
            head = NULL;
        }

        // Metodo para invertir la linked list

        Node* reverseList(Node* head) {
            // Necesito 3 punteros
            // prev = NULL; // Puntero al nodo anterior
            Node* prev = NULL;
            // curr = head; // Puntero al nodo actual
            Node* curr = head;
            // next = NULL; // Puntero al siguiente nodo 
            Node* next = NULL;

            while ( curr != NULL){
                // Guardar el siguiente nodo
                next = curr->next;

                // Hacer que el puntero curr , apunte al anterior 
                curr->next = prev;

                // Mover los punteros hacia adelante
                prev = curr;

                // Mover curr al siguiente nodo
                curr = next;
            }

            // Al final, prev será el nuevo head de la lista invertida
            head = prev;
            return head;
        }
};
