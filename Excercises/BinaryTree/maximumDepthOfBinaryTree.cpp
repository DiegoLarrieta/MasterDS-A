//  Leetcode 104 - Maximum Depth of Binary Tree
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

class Solution{
    public:
        int maxDepth(Node* root){
            // Caso base: si root es nulo la profundidad es -
            if(root == nullptr){
                return 0;
            }

            // Llamada recursiva para encontrar la profundidad de los subárboles izquierdo y derecho
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);

            // La profundidad del árbol es el máximo entre las profundidades de los subárboles más 1 para la raíz actual
            return max(leftDepth, rightDepth) + 1;
        }
};

