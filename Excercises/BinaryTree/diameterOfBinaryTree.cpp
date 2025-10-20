// Leetcode 543 - Diameter of Binary Tree

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
        int diameterOfBinaryTree(Node* root){
            int largestDiameter = 0;

            height(root, largestDiameter);

            return largestDiameter;
        }
    // Para calcular la altura de left y right
    private:
        int height(Node* node, int& largestDiameter){
            if(node == nullptr) return 0;

            // Calcular la altura de left
            int leftHeight =  height(node->left, largestDiameter);

            // Calcular la altura de right
            int rightHeight = height(node->left, largestDiameter);

            // El diametro es la suma de las alturas de left y right
            int diameter = leftHeight + rightHeight;

            // Obtener el diametro mas grande
            largestDiameter = max(largestDiameter, diameter);

            // Retornar la altura del nodo actual
            return max(leftHeight, rightHeight) + 1;
        }

};