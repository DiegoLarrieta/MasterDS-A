// LeetCode 112 - Path Sum
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
        bool hasPathSum(Node* root, int targetSum){
            // Current sum lo iniciamos en 0
            return hasSum(root, 0, targetSum);
        }
    private:
        bool hasSum(Node* node, int currentSum, int targetSum){
            // Si el nodo es nulo retornamos false 
            if(node == nullptr) return false;

            // current sum es la suma actual mas el valor del nodo actual 
            currentSum += node->data;

            // Si estoy en un nodo hoja (no tiene hijos izquierdos ni derechos), reviso si la suma acumulada hasta este punto
            // si currentSum es igual a targetSum retorno true, de lo contrario false
            if(node -> left == nullptr && node ->right == nullptr){
                return currentSum == targetSum; 
            }

            return hasSum(node-> left , currentSum, targetSum) || hasSum(node-> right, currentSum, targetSum);
        }

};