// Double Linked list
#include <iostream>
using namespace std;

// Paso 1: Definir la estructura basica del Nodo

struct Node{
    int data;
    Node* next;
    Node* prev;

    // Constructor para inicializar un nodo
    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Paso 2: Crear la clase de la lista enlazada doble 
class DoublyLinkedList{
    private:
        Node *head; // Puntero al primer nodo de la lista
        Node *tail; // Puntero al ultimo nodo de la lista
    public:
        // Constructor para inicializar una lista vacia
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }

        // Paso 3 , crear los metodos de la linked list
        // 🟢 Insertar al inicio de la lista
        //  Complejidad O(1)
        void insertAtHead(int value){
            Node* newNode = new Node(value);
            newNode->next = head;
            newNode->prev = NULL;
            if(head != NULL) {
                head->prev = newNode; // Si la lista no está vacía, conectar el nodo actual de la cabeza al nuevo nodo
            }
            head = newNode;
            if(tail == NULL) { // Si la lista estaba vacía, el nuevo nodo es también el último nodo
                tail = newNode;
            }
        }

        // 🟢 Insertar al final de la lista
        // ⏱️ Complejidad: O(1)
        void insertAtTail(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode; // Conectar el último nodo al nuevo nodo
            newNode->prev = tail; // Conectar el nuevo nodo al último nodo
            tail = newNode; // Actualizar el último nodo a ser el nuevo nodo
        }

        // 🟢 Insertar en una posicion especifica
        // ⏱️ Complejidad: O(n)
        void insertAtPosition(int value, int position){
            if(position == 0){
                insertAtHead(value);
                return;
            }
            Node* newNode = new Node(value);
            Node* temp = head;

            // Recorrer la lista hasta la posicion deseada
            for(int i = 0; i < position - 1;i++){
                // Si llegamos al final de la lista antes de la posicion deseada
                if(temp == NULL){
                    cout << "❌ Posición fuera de rango." << endl;
                    delete newNode; // Liberar memoria del nuevo nodo
                    return;
                }
                temp = temp->next;
            }
            // Insertar el nuevo nodo en la posicion deseada
            newNode->next = temp->next;
            newNode->prev = temp;

            if(temp->next != NULL){

                temp->next->prev = newNode; // Conectar el siguiente nodo al nuevo nodo
            } else {
                tail = newNode; // Si estamos insertando al final, actualizar el tail
            }
            temp->next = newNode; // Conectar el nodo actual al nuevo nodo

        }

        // 🟢 Eliminar el nodo al inicio
        //  Complejidad O(1)
        void deleteAtHead(){
            if(head == NULL){
                cout << "❌ La lista está vacía, no se puede eliminar." << endl;
                return; // Si la lista está vacía, no hay nada que eliminar
            }
            Node* temp = head;
            head = head->next;
            if(head != NULL){
                head->prev = NULL; // Si la lista no está vacía, actualizar el puntero previo de la nueva cabeza
            } else {
                tail = NULL; // Si la lista queda vacía, actualizar el tail a NULL
            }
            delete temp; // Liberar memoria del nodo eliminado
        }

        // 🟢 Eliminar el nodo del final
        // ⏱️ Complejidad: O(1)
        void deleteAtTail(){
            // Verificar si la lista esta vacia
            if(head == NULL){
                cout << "❌ La lista está vacía, no se puede eliminar." << endl;
                return; // Si la lista está vacía, no hay nada que eliminar
            }

            // Crear un puntero temporal que apunta al tail
            Node* temp = tail; 

            // Mover el tail al nodo anterior
            tail = tail->prev;

            if(tail != NULL) {
                tail->next = NULL; // Si la lista no está vacía, actualizar el siguiente de la nueva cola a NULL
            } else {
                head = NULL; // Si la lista queda vacía, actualizar la cabeza a NULL
            }
            delete temp;
             
        }

        void deleteAtPosition(int position){
            // Verificar si la lista esta vacia
            if(head == NULL){
                cout << "❌ La lista está vacía, no se puede eliminar." << endl;
                return; // Si la lista está vacía, no hay nada que eliminar
            }
            if(position == 0){
                deleteAtHead();
                return;
            }

            // Creamos un puntero que apunta a la cabeza
            Node* temp = head;

            // Recorremos la lista hasta llegar al nodo anterior al que queremos eliminar
            for(int i = 0; i < position -1; i++){
                temp = temp->next;
                // Si llegamos al final de la lista antes de la posicion deseada
                if(temp == NULL || temp->next == NULL){
                    cout << "❌ Posición inválida." << endl;
                    return; // Salir del metodo
                }
            }
            // Guardar el nodo a eliminar
            Node* nodeToDelete = temp->next;
            if(nodeToDelete == NULL){
                cout << "❌ Posición inválida." << endl;
                return; // Si el nodo a eliminar es NULL, salir del metodo
            }
            // Hacer que el nodo anterior apunte al siguiente nodo
            temp->next = nodeToDelete->next;

            // Hacer que el siguiente nodo apunte al nodo anterior
            if(nodeToDelete->next != NULL){
                nodeToDelete->next->prev = temp; // Conectar el siguiente nodo al nodo anterior
            }

            // Liberar memoria del nodo eliminado
            delete nodeToDelete;
        }

        // 🟢 Buscar un nodo por valor
        // Complejidad O(n)
        void searchNode(int value){
            // Crear un puntero temporal que apunte a la cabeza
            Node* temp = head;

            // Recorrer la lista hasta encontrar el nodo con el valor buscado
            while(temp != NULL){
                if(temp->data == value){
                    cout << "✅ Nodo encontrado con valor: " << value << endl;
                    return; // Salir del metodo si se encuentra el nodo
                }
                temp = temp->next; // Moverse al siguiente nodo
            }
            cout << "❌ Nodo no encontrado con el valor: " << value << endl; // Si no encontramos el nodo, mostramos un mensaje

        }

        // Acceder a un nodo
        // Complejidad O(n)

        void accessNode(int index){
            Node* temp = head;
            int currentIndex = 0;

            while(temp != NULL){
                if(currentIndex == index){
                    cout << "✅ Nodo encontrado en el índice " << index << " con el valor: " << temp->data << endl;
                    return; // Si encontramos el nodo, salimos del metodo
                }
                temp = temp->next;
                currentIndex++;
            }
            cout << "❌ Índice fuera de rango." << endl; // Si no encontramos el nodo, mostramos un mensaje
        }

        // Obtener la longitud de la lista
        // Complejidad O(n)
        int lenghtLinkedList(){
            Node* temp = head;
            int lenght = 0;

            while(temp!=NULL){
                lenght++;
                temp = temp->next;
            }
            cout << "La longitud de la lista es: " << lenght << endl; // Mostrar la longitud de la lista
            return lenght; // Retornar la longitud de la lista
        }

        

        // Imprimir lista
        // Método para imprimir la lista
        void printList() {
            if (head == NULL) { // Si la lista está vacía
                cout << "La lista está vacía." << endl;
                return;
            }
            Node* temp = head; // Empezar desde la cabeza
            while (temp != NULL) {
                cout << temp->data << " <-> ";
                temp = temp->next; // Moverse al siguiente nodo
            }
            cout << "NULL" << endl;
        }
};

int main(){
    DoublyLinkedList list;

    // Insertar elementos al inicio de la lista O(1)
    list.insertAtHead(3);         // Lista: 3
    list.insertAtHead(2);         // Lista: 2 -> 3
    list.insertAtHead(1);         // Lista: 1 -> 2 -> 3
    list.printList();             // Imprimir la lista: 1 <-> 2 <-> 3 <-> NULL

    // Insertar al final de la lista O(n)
    list.insertAtTail(4);         // Lista: 1 <-> 2 <-> 3 <-> 4
    list.insertAtTail(6);         // Lista: 1 <-> 2 <-> 3 <-> 4 <-> 6
    list.printList();             // Imprimir la lista: 1 <-> 2 <-> 3 <-> 4 <-> 6 <-> NULL

    // Insertar en una posicion especifica O(n)
    list.insertAtPosition(5, 4);   // Lista: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    list.printList();             // Imprimir la lista: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL

    // Eliminar el nodo al inicio O(1)
    list.deleteAtHead();          // Lista: 2 <-> 3 <-> 4 <-> 5 <-> 6
    list.printList();             // Imprimir la lista: 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL

    // Eliminar el nodo al final O(1)
    list.deleteAtTail();          // Lista: 2 <-> 3 <-> 4 <-> 5
    list.printList();             // Imprimir la lista: 2 <-> 3 <-> 4 <-> 5 <-> NULL

    // Eliminar el nodo en una posicion especifica O(n)
    list.deleteAtPosition(2);     // Lista: 2 <-> 3 <-> 5
    list.printList();             // Imprimir la lista: 2 <-> 3 <-> 5 <-> NULL

    // Buscar un nodo por valor O(n)
    list.searchNode(3);           // Buscar el nodo con el valor 3

    // Acceder a un nodo por índice O(n)
    list.accessNode(1);           // Acceder al nodo en el índice 1 (valor 3)

    // Obtener la longitud de la lista O(n)
    list.lenghtLinkedList();      // Obtener la longitud de la lista
    
    return 0;
}