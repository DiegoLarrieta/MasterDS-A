#include <iostream>
using namespace std;

// Nodo de la Singly Linked List
struct Node {
    int data;       // Valor del nodo
    Node* next;     // Puntero al siguiente nodo

    // Constructor para inicializar un nodo
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Clase para la Singly Linked List
class SinglyLinkedList {
private:
    Node* head; // Puntero al primer nodo de la lista

public:
    // Constructor para inicializar la lista vacía
    SinglyLinkedList() {
        head = NULL;
    }

    // Método para insertar un nodo al inicio
    void insertAtHead(int value) {
        Node* newNode = new Node(value); // Crear un nuevo nodo
        newNode->next = head;            // Apuntar al nodo actual de la cabeza
        head = newNode;                  // Actualizar la cabeza
    }

    // Método para eliminar un nodo por valor
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        // Si el nodo a eliminar es la cabeza
        if (head->data == value) {
            Node* temp = head;
            head = head->next; // Mover la cabeza al siguiente nodo
            delete temp;       // Liberar memoria
            cout << "Node with value " << value << " deleted." << endl;
            return;
        }

        // Buscar el nodo a eliminar
        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }

        // Si no se encuentra el nodo
        if (current->next == NULL) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        // Eliminar el nodo
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp; // Liberar memoria
        cout << "Node with value " << value << " deleted." << endl;
    }

    // Método para buscar un nodo por valor
    bool searchNode(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true; // Nodo encontrado
            }
            temp = temp->next;
        }
        return false; // Nodo no encontrado
    }

    // Método para acceder a un nodo por índice
    int accessNode(int index) {
        Node* temp = head;
        int currentIndex = 0;

        while (temp != NULL) {
            if (currentIndex == index) {
                return temp->data; // Retornar el valor del nodo en el índice
            }
            temp = temp->next;
            currentIndex++;
        }

        throw out_of_range("Index out of range."); // Lanzar excepción si el índice no es válido
    }

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

int main() {
    SinglyLinkedList list;

    // Insertar elementos en la lista
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.insertAtHead(40);

    list.accessNode(1); // Acceder al nodo en el índice 1
    

    list.deleteNode(20); // Eliminar el nodo con valor 20

    list.searchNode(30); // Buscar el nodo con valor 30


    // Imprimir la lista
    cout << "Singly Linked List: ";
    list.printList();

    return 0;
}