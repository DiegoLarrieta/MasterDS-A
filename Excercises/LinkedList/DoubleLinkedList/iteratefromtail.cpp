/*

🔄 4. Buscar un valor recorriendo desde el final
🎯 Objetivo: Dado un valor x, recorre la lista desde el final (tail) hacia el inicio y determina si existe ese valor.

🧪 Ejemplo:
Input: 1 <-> 3 <-> 5 <-> 7 <-> 9, x = 5
Output: ✅ Valor 5 encontrado desde el final

Input: 1 <-> 3 <-> 5 <-> 7 <-> 9, x = 4
Output: ❌ Valor 4 no encontrado


*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    //Constructor para inicializar
    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    };
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;

    public:
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }

        // Método para buscar un valor desde el final
        bool searchFromTail(int value){
            if(tail == NULL){
                cout << "La lista está vacía." << endl;
                return false; // Si la lista está vacía, no hay nada que buscar
            }
            // Puntero que comienza desde tail
            Node* current = tail;
            while(current != NULL){
                if(current->data == value){
                    cout<< "✅ Valor " << value << " encontrado desde el final." << endl;
                    return true; // Si encontramos el valor, retornamos true
                }
                current = current->prev;
            }
            cout << "❌ Valor " << value << " no encontrado." << endl;
            return false; // Si llegamos al inicio sin encontrar el valor, retornamos false
        }
};

