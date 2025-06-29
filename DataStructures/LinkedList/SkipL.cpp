#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

/*
Junta las cualidades de una linkedlist y un array ( binary search )

Es muy eficiente para acceder, buscar , eliminar y insertar elementos O(log n)

Skip List es una estructura de datos probabilística que permite un acceso rápido a los elementos, similar a una lista enlazada pero con múltiples niveles de enlaces.

Nosotros definimos el número máximo de niveles y la probabilidad de que un nodo tenga un nivel más alto, que suele ser 0.5 (50%).

*/
using namespace std;

struct SkipListNode {
    int val;
    vector<SkipListNode*> forward;

    SkipListNode(int value, int level) {
        // Inicializar el nodo con una valor y un nivel
        val = value;
        forward.resize(level + 1, nullptr);
    }
};

class SkipList{
    private:
        int maxLevel;
        float probability;
        int currentLevel;
        SkipListNode* header;

    public:
        // Constructor para inicializar la Skip List
        SkipList(int maxLevel, float probability) {
            this->maxLevel = maxLevel;
            this->probability = probability;
            this->currentLevel = 0;
            header = new SkipListNode(INT_MIN, maxLevel);
        }

        // Destructor para liberar la memoria
        ~SkipList() {
            SkipListNode* current = header;
            while (current) {
                SkipListNode* next = current->forward[0];
                delete current;
                current = next;
            }
        }

        // Funcion para generar un nivel aleatorio
        int randomLevel(){
            int level = 0;
            while ((rand() % 100) < (probability * 100) && level < maxLevel) {
                level++;
            }
            return level;
        }

        // Funcion para insertar un nuevo nodo
        // O(log n) en promedio
        void insert(int value){
            SkipListNode* current = header;
            vector<SkipListNode*> update(maxLevel + 1, nullptr);

            // Encontrar la posicion de insercion
            for(int i = currentLevel; i >= 0; i--){
                while (current->forward[i] != nullptr && current->forward[i]->val < value) {
                    current = current->forward[i];
                }
                update[i] = current;
            }

            current = current->forward[0];
            // Si el valor no existe, insertarlo
            if(current == nullptr || current->val != value){
                int newLevel = randomLevel();

                if(newLevel > currentLevel){
                    for(int i = currentLevel + 1; i <= newLevel; i++){
                        update[i] = header;
                    }
                    currentLevel = newLevel;
                }
                // Crear un nuevo nodo y actualizar los punteros
                SkipListNode* newNode = new SkipListNode(value, newLevel);
                for(int i = 0; i <= newLevel; i++){
                    newNode->forward[i] = update[i]->forward[i];
                    update[i]->forward[i] = newNode;
                }
            }
        }

        // Funcion para buscar un valor
        // O(log n) en promedio
        void search(int value){
            SkipListNode* current = header;

            // Recorrer los niveles de la Skip List
            for(int i = currentLevel; i >= 0; i--){
                // Mientras el nodo actual no sea nulo y su valor sea menor que el valor buscado 
                //avanzamos al siguiente nodo que esta en el mismo nivel
                // Ej , estamos en el nodo 5 y buscamos 7, avanzamos en el mismo nivel
                while(current->forward[i] != nullptr && current->forward[i]->val < value){
                    current = current->forward[i];
                }
                // Si estamos en el nodo 5 y buscamos 3, solo nos bajamos de nivel
            }
            // Una vez que hemos llegado al nivel 0, verificamos si el nodo actual es el que buscamos
            current = current->forward[0];

            if(current != nullptr && current->val == value){
                cout<< "Valor " << value << " encontrado en la Skip List.\n";
            }else{
                cout<< "Valor " << value << " no encontrado en la Skip List.\n";
            }
        }

        // Funcion para eliminar un valor
        // O(log n) en promedio
        void remove(int value){
            SkipListNode* current = header;
            // Utilizamos un vector para almacenar los nodos que tienen punteros hacia el nodo a eliminar
            vector<SkipListNode*> update (maxLevel + 1, nullptr);

            // Encontrar todos los nodos que apuntan al nodo que queremos eliminar
            for(int i = currentLevel; i >= 0; i--){
                while(current->forward[i] != nullptr && current->forward[i]->val < value){
                    current = current->forward[i];
                }
                update[i] = current; // Guardamos el nodo anterior en cada nivel
            }
            // Una vez que hemos llegado al nivel 0, verificamos si el nodo actual es el que buscamos
            current = current->forward[0];

            // Cuando encontramos el valor , actualizamos los punteros de los nodos para eliminarlo 
            if(current != nullptr && current->val == value){
                for(int i = 0; i <= currentLevel; i++){
                    // Si el nodo a eliminar no es el siguiente del nodo anterior, no hacemos nada
                    if(update[i]->forward[i] != current){
                        break;
                    }
                    // Actualizamos el puntero del nodo anterior al nodo a eliminar
                    //aqui saltamos el nodo , por lo que se elimina
                    update[i]->forward[i] = current->forward[i];
                }
                // Si el nodo eliminado era el ultimo en su nivel, reducimos el nivel actual
                while(currentLevel > 0 && header->forward[currentLevel] == nullptr) {
                    currentLevel--;
                }
                delete current; // Liberar memoria del nodo eliminado
                cout << "Valor " << value << " eliminado de la Skip List.\n";

            }
        }
        // Mostrar toda la lista
        void display() {
            cout << "\n--- Skip List ---\n";
            for (int i = currentLevel; i >= 0; --i) {
                SkipListNode* node = header->forward[i];
                cout << "Nivel " << i << ": ";
                while (node != nullptr) {
                    cout << node->val << " ";
                    node = node->forward[i];
                }
                cout << endl;
            }
        }
};

int main(){

    srand(time(0)); // Inicializar la semilla aleatoria
    SkipList skipList(3, 0.5); // Crear una Skip List con maxLevel 3 y probabilidad 0.5

    // Insertar algunos valores O(log n)
    skipList.insert(1);
    skipList.insert(2);
    skipList.insert(3);
    skipList.insert(4);
    skipList.insert(5);
    skipList.insert(6);
    skipList.insert(7);
    skipList.insert(8);
    skipList.insert(9);
    skipList.insert(10);

    // Buscar algunos valores O(log n)
    skipList.search(5);
    skipList.search(11); // Valor no existente

    // Eliminar algunos valores O(log n)
    skipList.remove(3);

    // Mostrar la Skip List
    skipList.display();

    return 0;
}
