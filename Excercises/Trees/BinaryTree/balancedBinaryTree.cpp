// Leetcode 110 - Balanced Binary Tree

#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor para inicializar el nodo
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(Node* root) {
        // llamamos la funcion height que calcula si esta balanceado o no
        // mientras que no sea -1 retornara true que significa que si esta balanceado
        return height(root) != -1;
        
        
    }
private:
    // Hacer la funcion para calcular el height
    int height(Node* root){
        // Caso base si root es null
        if(root == nullptr){
            return false;
        }

        // Calcular el height de left y right con llamadas recurivas

        int leftHeight = height(root->left);
        // Si no estuvo balanceado left retornamos -1
        if (leftHeight == -1) return -1;

        int rightHeight = height(root->right);
        // Si no estuvo balanceado right retornamos -1
        if (rightHeight == -1) return -1;

        // Si la diferencia es mayor a 1 retornamos -1
        if(abs(leftHeight - rightHeight) > 1){
            return -1;
        }

        // Retornamos la altura del arbol
        return max(leftHeight, rightHeight) + 1;
    }
};