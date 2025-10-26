// 572. Subtree of Another Tree
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    // Constructor para inicializar el nodo
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
        bool isSubtree(Node *root, Node *subRoot){
            return hasSubtree(root, subRoot);
        }
    private:
        // Funcion para verificar si subRoot es un subtree de root
        bool hasSubtree(Node* root, Node* subRoot){
            // Si root es nulo , retornamos false;
            if(root == nullptr) return false;

            if(isSameTree(root, subRoot)) return true;

            return hasSubtree(root->left, subRoot) || hasSubtree(root->right, subRoot);

        }
        // Funcion para verificar si dos arboles son iguales
        bool isSameTree(Node* rootP, Node* subrootP){
            // Si ambos son nulos, son iguales
            if(rootP == nullptr && subrootP == nullptr) return true;

            // Si uno es nulo y el otro no, no son iguales retornamos false
            if(rootP == nullptr || subrootP == nullptr) return false;

            // Si los valores de los nodos son diferentes, retornamos false
            if(rootP->data != subrootP->data) return false;

            // Recurisvamente comparamos los subarboles izquierdo y derecho
            return isSameTree(rootP->left, subrootP->left) && isSameTree(rootP ->right, subrootP->right);
        }
};