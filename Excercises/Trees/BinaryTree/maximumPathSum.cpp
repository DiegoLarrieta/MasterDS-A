// Leetcode 124 - Binary Tree Maximum Path Sum

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    // Constructor para inicializar el nodo
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Time Complexity: O(N) donde N es el numero de nodos en el arbol
// Space Complexity: O(H) donde H es la altura del arbol debido a la pila de llamadas recursivas
class Solution{
    public:
        int maxPathSum(Node* root ){
            int result = root->data;
            dfs(root, result);
            return result;
        }
    private:
    // Vamos a hacer un dfs
        int dfs(Node* root, int& result){
            // Caso base
            if(root == nullptr) return 0;

            // Llamadas recursivas para los subarboles izquierdo y derecho

            // Calcular el maximo camino desde el subarbol izquierdo,
            int leftMax = max(dfs(root-> left, result), 0); 

            // Calcular el maximo camino desde el subarbol derecho, 
            // Se descarta el arbol si rightMax es negativo ejemplo max (-10,0) = el camino da 0
            int rightMax = max(dfs(root-> right, result), 0);

            // Calcular el maximo result
            result = max(result, root-> data + leftMax + rightMax);

            // Retornar el maximo camino , que es la suma del nodo actual mas el maximo camino de sus hijos
            return root-> data + max(leftMax, rightMax);
        }
};