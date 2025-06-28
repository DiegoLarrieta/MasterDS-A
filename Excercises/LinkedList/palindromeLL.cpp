/*
🎯 234. Verificar si una Linked list tiene un palindromo o no 
🎯 Retornar true o false

Input: 1 → 2 → 2 → 1
Output: true 


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

class SingleLinkedList{
    private:
        Node *head; // Puntero al primer nodo de la lista
    public:

    // Constructor para inicializar una lista vacia
    SingleLinkedList(){
        head = NULL;
    }

    // Metodo para saber si hay palindromo o no 
    bool isPalindrome(Node* head) {
        // Paso 1: Encontrar el punto medio de la lista hacer un nodo slow(1 en 1) y otro fast(2 en 2)
        Node* slow = head;
        Node* fast = head;
        // Cuando fast llegue a null , slow estara en el punto medio
        while(fast != NULL && fast->next !=NULL){
            slow = slow->next; // Mover slow 1 paso
            fast = fast->next->next; // Mover fast 2 pasos
        }
        // Paso 2: Invertir la segunda mitad de la lista
        // 1 - 2 - [2] - 1
        // Ya sabes que para invertir necesitas 3 punteros , prev , curr , next
        Node* prev = NULL;
        Node* curr = slow;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next; // Guardar el sigueinte nodo
            curr->next = prev; // Invertir el enlace
            // Mover los punteros hacia adelante
            prev = curr;
            curr = next;
        }
        // Paso 3: Comparar la primera mitad con la segunda mitad invertida
        // 1 - 2 / 1 - 2 
        Node* firstHalf = head; // Puntero a la primera mitad
        Node* secondHalf = prev; // Puntero a la segunda mitad invertida
        // prev esta en 2
        while(secondHalf != NULL){
            if(firstHalf->data != secondHalf->data){
                return false; // Si los datos no coinciden, no es un palindromo
            }
            // Mover firsthalf y secondHalf hacia adelante
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true; // Si todos los datos coinciden, es un palindromo
    }
};
