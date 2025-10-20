/*
Binary Tree
 Cuando cada nodo tiene como maximo 2 hijos ( izq | der )
 No hay regla de orden 
*/

#include <iostream>
#include <queue> // for level order traversal

using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor para inicializar el nodo
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Tree class
class BinaryTree {
    private:
        Node *root;

    public:
        // Constructor , arbol vacio
        BinaryTree() : root(nullptr) {}

        // 1. Insertar O(n)
        // Utilizamos BFS recorremos el arbol por niveles hasta encontrar un lugar vacio
        void insert(int val){
            //  Si esta vacio, creamos el nodo raiz
            if(root == nullptr){
                root = new Node(val);
                return;
            }
            // Usar una cola para hacer un recorrido por niveles
            queue<Node*> q;
            q.push(root);

            // Recorrer el arbol hasta encontrar un lugar vacio
            while(!q.empty()){
                Node* current = q.front(); // Obtener el nodo actual
                q.pop();// Sacarlo de la cola

                // Si el hijo izquierdo esta vacio, insertar el nuevo nodo ahi
                if(current->left == nullptr ){
                    current->left = new Node(val);
                    return;
                }
                else{
                    q.push(current->left); // Si no, agregar el hijo izquierdo a la cola
                }

                // Si el hijo derecho esta vacio, insertar el nuevo nodo ahi
                if(current -> right == nullptr){
                    current->right = new Node(val);
                    return;
                }
                else{
                    q.push(current->right); // Si no, agregar el hijo derecho a la cola
                }

            }

        }
        // 2. Search O(n)
        bool search(int val){
            if(root == nullptr){
                return false; // Arbol vacio
            }

            queue<Node*> q;
            q.push(root);

            while(!q.empty()){//mientras que la cola no este vacia
                Node* current = q.front();
                q.pop();

                if(current->data == val){
                    return true; // Valor encontrado
                }
                // Agregas left a la cola
                if(current->left != nullptr){
                    q.push(current->left);
                }

                // Agregas right a la cola
                if(current->right != nullptr){
                    q.push(current->right);
                }

            }
            return false; // Valor no encontrado
        }

        // 3. Delete O(n)
        bool deleteValue(int val){
            //  Si esta vacio, creamos el nodo raiz
            if(root == nullptr){
                return false; // Arbol vacio
            }

            // Caso especial si el arbol solo tiene un nodo(root)
            if(root->left == nullptr && root->right == nullptr){
                if(root->data == val){
                    delete root;
                    root = nullptr;
                    return true;
                }
                else{
                    return false; // Valor no encontrado
                }
            }

            // Recuerda que utilizamos BFS para recorrer el arbol
            queue<Node*> q;
            q.push(root);

            Node* target = nullptr; // Nodo a eliminar
            Node* current = nullptr; 

            while(!q.empty()){
                current = q.front();
                q.pop();

                if(current->data == val){
                    target = current; // Encontramos el nodo a eliminar
                }

                // Agregas left a la cola
                if(current->left != nullptr){
                    q.push(current->left);
                }

                // Agregas right a la cola
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            // Si no encontramos el nodo a eliminar
            if(target == nullptr){
                return false; // Valor no encontrado
            }

           Node* deepestNode = current; // El ultimo nodo visitado es el mas profundo

           // Si el objetivo no es el nodo mas profundo copiamos su valor al objetivo
            if(target != deepestNode){
                target->data = deepestNode->data;
            }

            // 5) Segundo BFS para encontrar el padre del deepest y cortarlo
            q = queue<Node*>();
            q.push(root);

            while (!q.empty()) {
                Node* node = q.front(); q.pop();

                if (node->left) {
                    if (node->left == deepestNode) {
                        node->left = nullptr;
                        break;
                    }
                    q.push(node->left);
                }
                if (node->right) {
                    if (node->right == deepestNode) {
                        node->right = nullptr;
                        break;
                    }
                    q.push(node->right);
                }
            }
            // 6) Liberar el nodo deepest
            delete deepestNode;
            return true; 
        }

        

        // Imprimir el arbol
        void printLevelOrder(){
            if(root == nullptr){
                cout << "El arbol esta vacio" << endl;
                return;
            }
            queue<Node*> q;
            q.push(root);

            while(!q.empty()){
                Node* current = q.front();
                q.pop();

                cout<< current->data << " ";
                if(current -> left != nullptr){
                    q.push(current->left);
                }
                if(current -> right != nullptr){
                    q.push(current->right);
                }
            }
            cout << endl;
        } 
};

int main(){
    BinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    cout << "Level Order Traversal of the Binary Tree: ";
    tree.printLevelOrder(); // Output: 1 2 3 4 5

    cout << "Searching for 3 in the tree: " << (tree.search(3) ? "Found" : "Not Found") << endl; // Output: Found

    cout << "Deleting 3 from the tree." << endl;
    tree.deleteValue(3);
    tree.printLevelOrder(); // Output: 1 2 5 4

    return 0;
}