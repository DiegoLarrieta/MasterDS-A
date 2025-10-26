// Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal

#include <iostream>
#include <unordered_map>
#include <vector>
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
        Node* buildTree(vector<int>& preorder, vector<int>& inorder){
            // 1. Llenar el mapa con los indices del recorrido inorder
            for(int i = 0; i < inorder.size(); i++){
                inOrderIndexMap[inorder[i]] = i;
            }

            // 2. Llamar a la funcion dfs para construir el arbol
            return dfs(preorder, 0, inorder.size() - 1);
        }   
    private:
        // 1. Crear un mapa para almacenar los indices de los valores en el recorrido inorder
        // clave: valor del nodo, valor: indice en inorder
        unordered_map<int, int> inOrderIndexMap;

        // 2. Crear variable para rastrear el indice actual en el recorrido preorder
        int preOrderIndex = 0;

        // 3. Funcion recursiva para construir el arbol, utilizando dfs
        // inStart e inEnd definen el rango actual en el recorrido inorder
        Node* dfs(vector<int>&preorder, int inStart, int inEnd){
            // Caso base: si el inidce de inicio es mayor que el indice de fin, retornar nullptr
            if(inStart > inEnd){
                return nullptr;
            }

            // 4. Obtener el valor del nodo raiz desde el recorrido preorder, y despues lo movemos 
            int rootVal = preorder[preOrderIndex++];

            // 5. Crear el nodo raiz
            Node* root = new Node(rootVal);

            // 6. Obtener el indice del nodo raiz en el recorrido inorder
            int mid = inOrderIndexMap[rootVal]; // mid es el indice de la posicion del nodo raiz en inorder

            // 7. Construir el subarbol izquierdo y derecho recursivamente
            root-> left = dfs(preorder, inStart, mid - 1);
            root-> right = dfs(preorder, mid + 1, inEnd);
            
            return root;
        }

};