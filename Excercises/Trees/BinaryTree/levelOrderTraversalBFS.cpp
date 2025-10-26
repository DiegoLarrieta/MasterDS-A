// Leetcode 102. Binary Tree Level Order Traversal

#include <iostream>
#include <vector>
#include <queue>// para bfs

using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor para inicializar el nodo
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// O(n) time complexity, 
// O(n) space complexity
class Solution{
    public:
        vector<vector<int>> levelOrder(Node* root){
            // Vector para almacenar el resultado final
            vector<vector<int>> result;

            // Si el arbol esta vacio, retornamos el vector vacio
            if(root == nullptr) return result;

            // Cola para realizar el recorrido BFS
            queue<Node*> q;
            q.push(root);// Agregamos la raiz a la cola

            while(!q.empty()){
                // Vector para almacenar los valores de los nodos en el nivel actual
                vector<int> currentLevel;

                int levelSize = q.size(); // Numero de nodos en el nivel actual

                // Procesamos todos los nodos en el nivel actual
                for(int i = 0; i < levelSize; i++){
                    // Sacamos el nodo de la cola
                    Node* currentNode = q.front();
                    q.pop();

                    // Agregamos el valor del nodo actual al nivel actual
                    currentLevel.push_back(currentNode->data);

                    // Agregamos los hijos izquierdo y derecho a la cola si existen  
                    if(currentNode->left != nullptr){
                        q.push(currentNode->left);
                    }
                    if(currentNode->right != nullptr){
                        q.push(currentNode->right);
                    }
                }
                // Agregamos el nivel actual al resultado final
                result.push_back(currentLevel);
            }
            return result;
        }
};