// Leetcode 230. Kth Smallest Element in a BST

#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    public: 
        int kthSmallest(Node* root, int k){
            // Inicializamos count con k
            count = k;

            
            // Iniciamos el DFS in order
            dfs(root);

            // Retornamos la respuesta
            return ans;
        }
    private:
        // Vamos a hacer un DFS in order recursivo

        // Declarar variable que lleva la cuenta del valor k
        int count ;

        // Declarar la variable para almacenar el resultado
        int ans;

        void dfs(Node* node){
            // cuado count llegue a 0, hemos encontrado el k-esimo elemento mas pequeño

            // Caso base
            if(node == nullptr) return;

            // Recorremos el subarbol izquierdo
            dfs (node-> left);

            // Visitamos el nodo actual
            count--;

            if(count == 0){
                ans = node->data;
                return;
            }

            // Recorremos el subarbol derecho
            dfs(node-> right);

            
        }
};