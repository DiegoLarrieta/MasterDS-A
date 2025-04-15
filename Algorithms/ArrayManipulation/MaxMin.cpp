#include <iostream>
#include <vector>
using namespace std;

// Función que devuelve el máximo y mínimo en un vector
pair<int, int> EncontrarMaxMin(const vector<int>& arr) {
    // Inicializamos con el primer valor del vector
    int max = arr[0];
    int min = arr[0];

    // Recorremos el vector desde el segundo elemento
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i]; // Actualizamos el máximo si encontramos uno mayor
        }
        if (arr[i] < min) {
            min = arr[i]; // Actualizamos el mínimo si encontramos uno menor
        }
    }

    // Retornamos ambos valores como un par
    return {max, min};
}

int main() {
    // Ejemplo de vector
    vector<int> nums = {4, 9, 1, 7, 3, 10, 2};

    // Llamamos a la función
    pair<int, int> resultado = EncontrarMaxMin(nums);

    // Mostramos el resultado
    cout << "Máximo: " << resultado.first << endl;
    cout << "Mínimo: " << resultado.second << endl;

    return 0;
}
