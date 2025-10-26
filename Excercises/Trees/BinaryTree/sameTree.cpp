// Leetcode 100 - Same Tree

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
        bool isSameTree(Node* p, Node* q){

            // Llamamos a la funcion isSame que compara los nodos
            return isSame(p , q);

        }
    // Hacemos una variable para ir recorriendo los nodos y los compara
    private:
        bool isSame(Node* p , Node* q){
            // Si ambos nodos son nulos , son iguales , retornamos true
            if(p == nullptr && q == nullptr){
                return true;
            }

            // Si uno de los nodos es nulo y el otro no , no son iguales , retornamos false
            if(p == nullptr || q == nullptr){
                return false;
            }

            // Si los valores de los nodos son diferentes , no son iguales , retornamos false
            if(p->data != q->data){
                return false;
            }

            // Llamada recursiva para comparar los hijos izquierdo y derecho
            return isSame(p->left , q->left) && isSame(p->right , q->right);
        }
};