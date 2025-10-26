// Leetcode 297. Serialize and Deserialize Binary Tree

#include <iostream>
#include <string>
#include <sstream>

#include <vector>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    // Constructor para inicializar el nodo
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Codec {
    public:
    
        // Encodes a tree to a single string.
        string serialize(Node* root) {
            vector<string> result;
            serializeDFS(root, result);
            // Unir los valores en una sola cadena separados por comas
            //return join(result, ",");
        }
    
        // Decodes your encoded data to tree.
        Node* deserialize(string data) {
            //vector<string> nodes = split(data, ",");
            int i = 0;
            //return deserializeDFS(nodes, i);
        }
    // Cread dfs para serializar y deserializar
    private:
        void serializeDFS(Node* root, vector<string>&result){
            // Caso base , retornamos N como significado de null
            if (root == nullptr){
                result.push_back("null");
                return;
            };

            // 1. Agregar el valor del nodo actual al resultado
            result.push_back(to_string(root-> data));

            // 2. Llamada recursiva al subarbol izquierdo
            serializeDFS(root-> left, result);
            // 3. Llamada recursiva al subarbol derecho
            serializeDFS(root-> right, result);
        }

        Node* deserializeDFS(vector<string>&nodes, int& i){
            // Caso base , si leemos "null", retornamos nullptr y nos movemos al siguiente indice
            if(nodes[i] == "null"){
                i++;
                return nullptr;
            }
            // 1. Crear el nodo con el valor actual
            // con stoi convertimos string a int
            Node* root = new Node(stoi(nodes[i]));

            // 2. Movernos al siguiente indice
            i++;

            // 3. Llamada recursiva para construir el subarbol izquierdo
            root-> left = deserializeDFS(nodes, i);
            // 4. Llamada recursiva para construir el subarbol derecho
            root-> right = deserializeDFS(nodes, i);
            return root;
        }
    };