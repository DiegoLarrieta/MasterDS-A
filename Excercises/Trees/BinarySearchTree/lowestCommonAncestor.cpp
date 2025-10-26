// Leetcode 235. Lowest Common Ancestor of a Binary Search Tree

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
        Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
            
            // 1. Crear puntero lca inicializado en la raiz
            Node* lca = root;

            while(root != nullptr){
                // 2. Si q y p son mayores que lca, entonces el lca esta en el subarbol derecho
                if(root-> data < p-> data && root->data < p-> data){
                    root = root-> right;
                }
                // 3. Si q y p son menores que lca, entonces el lca esta en el subarbol izquierdo
                else if(root-> data > p-> data && root->data > p-> data){
                    root = root-> left;
                }
                // 4. Si no , significa que q y p estan en lados opuestos, entonces lca es root
                else{
                    Node* lca = root;
                    break;
                }
            }
            return lca;
        }
};