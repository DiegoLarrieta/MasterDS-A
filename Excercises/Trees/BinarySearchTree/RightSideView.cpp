// Leetcode 199. Binary Tree Right Side View
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

class Solution {
public:
    vector<int> rightSideView(Node* root) {
        // 1. Crear un vector para almacenar el resultado
        vector<int> result;

        // 2. Crear una queue para almacenar los nodos del nivel actual
        queue<Node*> nodeLevelQueue;

        // Agregamos root al queue
        nodeLevelQueue.push(root);

        // Edge , si queue esta vacio retornamos el vector vacio 
        if(root == nullptr) return result;

        // 3. Creamos puntero rightmost
        Node* rightMost = nullptr;

        // 4. Vamos a iterar sobre el queue 
        for(int i = 0 ; i < nodeLevelQueue.size() ; i++){
            // Nuestro nodo actual es el que esta al frente del queue
            Node* node = nodeLevelQueue.front();

            // Ya procesado lo eliminamos
            nodeLevelQueue.pop();


            // Si el nodo no es nulo 
            if(node != nullptr){
                // Asignamos como rightmost el nodo actual 
                rightMost = node;

                // Agregamos el hijo izquierdo al queue
                nodeLevelQueue.push(node->left);

                //Agregamos el hijo derecho al queue
                nodeLevelQueue.push(node->right);
            }
            
        }
        // 5. Agregamos el valor de rightmost al resultado
        result.push_back(rightMost->data);
        
        return result;
    }

};