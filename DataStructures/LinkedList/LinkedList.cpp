#include <iostream>
using namespace std;

// Paso 1: Definir la estructura basica del Nodo

struct Node{
    int data;
    Node* next;

    // Constructor para inicializar un nodo
    Node(int value){
        data = value;
        next = NULL;
    }
};

// Paso 2: Crear la clase de la lista enlazada
// Esta clase se va a encargar de gestionar los nodos, dentro de la clase solo necesitamos un puntero al inicio de la lista
class SinglyLinkedList{
    private:
        Node *head; // Puntero al primer nodo de la lista

    public:
        // Constructor para inicializar una lista vacia
        SinglyLinkedList(){
            head = NULL;
        }

        // Paso 3 , crear los metodos de la linked list 

        // 🟢 Insertar al inicio de la lista
        //  Complejidad O(1)
        void insertAtHead(int value){
            Node* newNode = new Node(value); // Crear el nuevo nodo llamado newNode
            newNode->next = head;            // Apuntar al nodo actual de la cabeza
            head = newNode;                  // Actualizar la cabeza
        }
        // 🟢 Insertar al final de la lista
        // ⏱️ Complejidad: O(n)
        void insertAtTail(int value){
            Node* newNode = new Node(value);

            // Si la lista esta vacia, el nuevo nodo es la cabeza
            if(head == NULL){
                head = newNode;
                return;
            }
            // Para insertar al final, necesitamos recorrer la lista hasta el ultimo nodo
            Node* temp = head; // Crea un puntero llamado temp que apunta al mismo nodo que head
            while(temp->next != NULL){ // Mientras el siguiente nodo no sea nulo
                temp = temp->next; // Moverse al siguiente nodo
            }
            // Cuando temp->next == nullptr, significa que temp es el último nodo.
            temp ->next = newNode; // Ahi le conectamos el nuevo nodo
        }

        // 🟢 Insertar en una posicion especifica (0-based)
        // ⏱️ Complejidad: O(n)
        void insertAtPosition(int value, int position){
            // Si la posicion es 0, simplemente llamamos al metodo insertAtHead
            if(position == 0){
                insertAtHead(value);
                return;
            }
            Node* newNode = new Node(value); // Crear un nuevo nodo
            Node* temp = head; // Crear un puntero temporal que apunta a la cabeza

            // Recorrer la lista hasta la posicion deseada
            for(int i = 0; i < position - 1; i++){
                // Si llegamos al final de la lista antes de la posicion deseada
                if(temp == NULL){ 
                    cout << "❌ Posición inválida.\n";
                    return; // Salir del metodo
                }
                // Avanzar temp hasta el nodo justo antes de la posición deseada ( pos - 1 )
                temp = temp->next; // Moverse al siguiente nodo
            }

            // Insertar el nuevo nodo en la posicion deseada

            // Hacer que el nuevo nodo apunte al siguiente nodo
            newNode ->next = temp ->next;

            // Hacer que el nodo anterior apunte al nuevo nodo
            temp ->next = newNode;
        }

        // 🟢 Eliminar un nodo del inicio
        //  Complejidad O(1)
        void deleteAtHead(){
            // Crear un nuevo puntero temporal que apunta a la cabeza
            Node* temp = head; 

            // Mover la cabeza al siguiente nodo
            head = head->next;

            // Liberar la memoria del nodo eliminado
            delete temp;

            // Verificar si la lista esta vacia
            if(head == NULL){
                cout << "❌ La lista esta vacia, no se puede eliminar." << endl;
                return; // Si la lista esta vacia, no hay nada que eliminar
            }
        }

        // 🟢 Eliminar el nodo del final
        // ⏱️ Complejidad: O(n)
        void deleteAtTail(){
            // Recorremos la lista hasta llegar al nodo anterior al ultimo
            Node* temp = head; // Crear un puntero temporal que apunta a la cabeza

            // Recorremos la lista hasta llegar al nodo penultimo si es que no es nulo 
            while(temp ->next->next != NULL){
                temp = temp->next; // Moverse al siguiente nodo
            }
            // Liberar memoria del ultimo nodo
            delete temp->next;

            // Hacer que el penultimo nodo apunte a NULL
            temp->next = NULL;

            // Verificar si la lista esta vacia
            // Si la lista esta vacia, head sera NULL
            if(head == NULL){
                cout << "❌ La lista esta vacia, no se puede eliminar." << endl;
                return; // Si la lista esta vacia, no hay nada que eliminar
            }

            // Si solo hay un nodo
            if(head->next == NULL){
                delete head; // Liberar memoria del nodo
                head = NULL; // Actualizar la cabeza a NULL
                return;
            }
        }

        // 🟢 Eliminar un nodo por valor
        // Complejidad O(n)
        void deleteAtPosition(int position){

            // Verificar si la lista esta vacia
            if(head == NULL){
                cout << "❌ La lista esta vacia, no se puede eliminar." << endl;
                return; // Si la lista esta vacia, no hay nada que eliminar
            }
            // Si la posicion es 0, simplemente llamamos al metodo deleteAtHead
            if(position == 0){
                deleteAtHead();
                return;
            }

            // Creamos un puntero temporal que apunta a la cabeza
            Node* temp = head;

            // Recorremos la lista hasta llegar al nodo anterior al que queremos eliminar
            for(int i = 0 ; i < position - 1; i++){
                temp = temp->next; // Moverse al siguiente nodo
            }

            // Guardar el nodo a eliminar
            Node* nodeToDelete = temp->next;

            // Hacer que el nodo anterior apunte al siguiente nodo
            // Haz que temp->next salte el nodo actual y apunte al siguiente:
            temp->next = temp->next->next;

            // Liberar memoria del nodo eliminado
            delete nodeToDelete;

        }

        // 🟢 Buscar un nodo por valor
        // Complejidad O(n)

        void searchNode(int value){
            // Crear un puntero temporal que apunte a la cabeza 
            Node* temp = head;

            // Recorremos la lista hasta encontrar el nodo con el valor buscado
            while(temp != NULL){
                if(temp->data == value){
                    cout << "✅ Nodo encontrado con el valor: " << value << endl;
                    return; // Si encontramos el nodo, salimos del metodo
                }
                temp = temp->next; // Moverse al siguiente nodo
            }
            cout << "❌ Nodo no encontrado con el valor: " << value << endl; // Si no encontramos el nodo, mostramos un mensaje
        }

        // 🟢 Acceder a un nodo
        // Complejidad O(n)

        void accessNode(int index){

            // Crear un puntero temporal que apunte a la cabeza
            Node* temp = head; 
            int currentIndex = 0; // Contador para el índice actual

            // Recorremos la lista hasta llegar al nodo en el índice deseado
            while(temp != NULL){
                if(currentIndex == index){
                    cout << "✅ Nodo encontrado en el índice " << index << " con el valor: " << temp->data << endl;
                    return; // Si encontramos el nodo, salimos del metodo
                }
                temp = temp->next; // Moverse al siguiente nodo
                currentIndex++; // Incrementar el índice actual
            }
            cout << "❌ Índice fuera de rango." << endl; // Si no encontramos el nodo, mostramos un mensaje
        }

        // Obtener la longitud de la lista
        // Complejidad O(n)

        void lengthLinkedList(){
            Node* temp = head; // Crear un puntero temporal que apunte a la cabeza
            int length = 0; // Contador para la longitud de la lista

            // Recorremos la lista hasta llegar al final
            while(temp != NULL){
                length++; // Incrementar el contador de longitud
                temp = temp->next; // Moverse al siguiente nodo
            }
            cout << "La longitud de la lista es: " << length << endl; // Mostrar la longitud de la lista
        }

        // Imprimir lista
        // Método para imprimir la lista
        void printList() {
            Node* temp = head; // Empezar desde la cabeza
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next; // Moverse al siguiente nodo
            }
            cout << "NULL" << endl;
        }

        
};

int main(){
    SinglyLinkedList list;

    // Insertar elementos al inicio de la lista O(1)
    list.insertAtHead(3);         // Lista: 3
    list.insertAtHead(2);         // Lista: 2 -> 3
    list.insertAtHead(1);         // Lista: 1 -> 2 -> 3
    list.printList();             // Imprimir la lista: 1 -> 2 -> 3 -> NULL

    // Insertar al final de la lista O(n)
    list.insertAtTail(4);         // Lista: 1 -> 2 -> 3 -> 4
    list.insertAtTail(6);         // Lista: 1 -> 2 -> 3 -> 4 -> 6
    list.printList();             // Imprimir la lista: 1 -> 2 -> 3 -> 4 -> 6 -> NULL

    // Insertar en una posicion especifica O(n)
    list.insertAtPosition(5, 4);   // Lista: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    list.printList();             // Imprimir la lista: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

    /****************/

    // Eliminar el nodo al inicio O(1)
    list.deleteAtHead();          // Lista: 2 -> 3 -> 4 -> 5 -> 6
    list.printList();             // Imprimir la lista: 2 -> 3 -> 4 -> 5 -> 6 -> NULL

    // Eliminar el nodo al final O(n)
    list.deleteAtTail();          // Lista: 2 -> 3 -> 4 -> 5
    list.printList();             // Imprimir la lista: 2 -> 3 -> 4 -> 5 -> NULL

    // Eliminar el nodo en una posicion especifica O(n)
    list.deleteAtPosition(2);     // Lista: 2 -> 3 -> 5
    list.printList();             // Imprimir la lista: 2 -> 3 -> 5 -> NULL

    /******************/

    // Buscar un nodo por valor O(n)
    list.searchNode(3);           // Buscar el nodo con el valor 3
    list.searchNode(99);          // Buscar el nodo con el valor 99 (no existe)

    /******************/

    // Acceder a un nodo por índice O(n)
    list.accessNode(1);           // Acceder al nodo en el índice 1 (valor 3)
    list.accessNode(5);           // Acceder al nodo en el índice 5 (fuera de rango)

    /******************/

    // Obtener la longitud de la lista O(n)
    list.lengthLinkedList();      // Obtener la longitud de la lista

}