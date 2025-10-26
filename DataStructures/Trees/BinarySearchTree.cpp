/*
Binary Search Tree
A binary search tree (BST) is a data structure that maintains a sorted order of elements, 
allowing for efficient insertion, deletion, and lookup operations. 
In a BST, each node has at most two children: 
the left child contains values less than the parent node, and the right child contains values greater than the parent node.
*/

#include <iostream>
// Vamos a utilizar recursividad para las operaciones

using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor para inicializar el nodo
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree{
    private: 
        Node* root;

    public:
        // Constructor , arbol vacio
        BinarySearchTree() : root(nullptr){}

        // 1. Insertar O(log N) 
        void insert(int val){
            root = insertRec(root, val);
        }
    private:
        Node* insertRec(Node* node, int val){
            // Si el nodo es nulo, creamos un nuevo nodo con el valor dado
            if(node == nullptr){
                return new Node(val);
            }
            // Si el valor es menor que el nodo actual, insertamos en el subarbol izquierdo
            if(val < node->data){
                node->left = insertRec(node->left, val);
            }
            // Si el valor es mayor que el nodo actual, insertamos en el subarbol derecho
            else if(val > node->data){
                node->right = insertRec(node->right, val);
            }
            // Retornamos el nodo (sin cambios si el valor ya existe)
            return node;
        }

    public:
        // 2. Search O(log N)
        bool search(int val){
            return searchRec(root, val);
        }
    private:
        bool searchRec(Node* node, int val){
            // Si el nodo es nulo, el valor no se encuentra en el arbol
            if(node == nullptr){
                return false;
            }
            // Si el valor es igual al nodo actual, lo hemos encontrado
            if(node->data == val){
                return true;
            }
            // Si el valor es menor, buscamos en el subarbol izquierdo
            if(val < node->data){
                return searchRec(node->left, val);
            }
            // Si el valor es mayor, buscamos en el subarbol derecho
            return searchRec(node->right, val);
        }
    public:
        // 3. Delete O(log N)
        void deleteValue(int val){
            root = deleteRec(root, val);
        }
    private:
        Node* deleteRec(Node* node, int val){
            // Si el nodo es nulo, retornamos nulo
            if(node == nullptr){
                return node;
            }
            // Si el valor es menor que el nodo actual, buscamos en el subarbol izquierdo
            if(val < node->data){
                node->left = deleteRec(node->left, val);
            }
            // Si el valor es mayor que el nodo actual, buscamos en el subarbol derecho
            else if(val > node->data){
                node->right = deleteRec(node->right, val);
            }
            // Si el valor es igual al nodo actual, este es el nodo a eliminar
            else{
                // Caso 1: Nodo con solo un hijo o sin hijos
                if(node->left == nullptr){
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                else if(node->right == nullptr){
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }

                // Caso 2: Nodo con dos hijos
                // Obtener el sucesor inorder (el nodo con el valor minimo en el subarbol derecho)
                Node* temp = node->right;

                while(temp->left != nullptr){
                    temp = temp->left;
                }

                // Copiar el valor del sucesor inorder al nodo actual
                node->data = temp->data;

                // Eliminar el sucesor inorder
                node->right = deleteRec(node->right, temp->data);

            }
            return node;
        }

    public:
        // Imprimir el arbol en orden
        void printInOrder(){
            printInOrderRec(root);
            cout << endl;
        }

        // Imprimir el arbol en preorden
        void printPreOrder(){
            printPreOrderRec(root);
            cout << endl;
        }

        // Imprimir el arbol en postorden
        void printPostOrder(){
            printPostOrderRec(root);
            cout << endl;
        }

    private:
        void printInOrderRec(Node* node){
            if(node == nullptr){
                return;
            }
            // Primero recorremos el subarbol izquierdo
            printInOrderRec(node->left);
            // Luego visitamos el nodo actual
            cout << node->data << " ";
            // Finalmente recorremos el subarbol derecho
            printInOrderRec(node->right);
        }

        void printPreOrderRec(Node* node){
            if(node == nullptr){
                return;
            }
            // Primero visitamos el nodo actual
            cout << node->data << " ";
            // Luego recorremos el subarbol izquierdo
            printPreOrderRec(node->left);
            // Finalmente recorremos el subarbol derecho
            printPreOrderRec(node->right);

        }

        void printPostOrderRec(Node* node){
            if(node == nullptr){
                return;
            }
            // Primero recorremos el subarbol izquierdo
            printPostOrderRec(node->left);
            // Luego recorremos el subarbol derecho
            printPostOrderRec(node->right);
            // Finalmente visitamos el nodo actual
            cout << node->data << " ";
        }

};

int main(){
    BinarySearchTree bst;

    // Insertar valores
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Imprimir en orden
    cout << "Inorder traversal: ";
    bst.printInOrder();

    // Buscar valores
    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (bst.search(90) ? "Found" : "Not Found") << endl;

    // Eliminar un valor
    bst.deleteValue(20);
    cout << "Inorder traversal after deleting 20: ";
    bst.printInOrder();

    // Eliminar un valor
    bst.deleteValue(50);
    cout << "Inorder traversal after deleting 50: ";
    bst.printInOrder();

    return 0;
}