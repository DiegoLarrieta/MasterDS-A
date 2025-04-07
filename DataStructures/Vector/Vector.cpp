#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declaración de un vector de enteros
    vector<int> numeros;

    // Agregar elementos
    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);

    // Acceder a elementos
    cout << "Elemento en la posición 1: " << numeros[1] << endl;

    // Recorrer el vector con un for 
    cout << "Elementos del vector: ";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Eliminar el último elemento
    numeros.pop_back();

    // Recorrer de nuevo con un for range - based Ideal si solo necesitas leer cada elemento y no te importa su posición
    cout << "Después de eliminar el último: ";
    for (int x : numeros) {
        cout << x << " ";
    }
    cout << endl;

    // Insertar en una posición específica (al inicio)
    numeros.insert(numeros.begin(), 5);

    // Eliminar en una posición específica (posición 1)
    numeros.erase(numeros.begin() + 1);

    // Mostrar el contenido final
    cout << "Contenido final del vector: ";
    for (int x : numeros) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
