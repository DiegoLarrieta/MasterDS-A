//  Leetcode 226 - Invert Binary Tree
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
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(h) where h is the height of the tree (due to recursion stack)
class Solution {
    public:
        Node* invertTree(Node* root) {
            // Caso base: si el nodo es nulo, retornar nulo
            if (root == nullptr) {
                return nullptr;
            }

            // Intercambiar los hijos izquierdo y derecho
            Node* temp = root->left;
            root->left = root->right;
            root->right = temp;

            // Llamada recursiva para invertir los subárboles izquierdo y derecho
            invertTree(root->left);
            invertTree(root->right);

            return root; // Retornar la raíz del árbol invertido
        }
};
