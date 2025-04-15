/*
Ejercicio 1: Suma de cada ventana
🎯 Enunciado:
Dado un vector y un entero k, imprime la suma de cada subarreglo contiguo de tamaño k.

Ejemplo:

arr = {1, 3, 5, 2, 8, 0, 1}, k = 3
Output:
9   → 1 + 3 + 5  
10  → 3 + 5 + 2  
15  → 5 + 2 + 8  
10  → 2 + 8 + 0
9   → 8 + 0 + 1  

*/

#include <iostream>
#include <vector>
using namespace std;

void MostrarVentanasConSuma(const vector<int>&array, int k){
    // Declaro variable para calcular tamaño de array
    int n = array.size();

    // Validamos que la ventana no sea mas grande que el array
    if(k > n){
        cout << "Error la ventana es mas grande"<<endl;
        return; 
    }

    // Calculamos la primera ventana
    int sumaVentana = 0;
    for(int i = 0; i < k; i++){
        sumaVentana += array[i];
    }
    cout << sumaVentana << " → " << array[0] << " + " << array[1] << " + " << array[2] << endl;

    // Deslizamos la ventana
    for(int i = k ; i < n; i++){
        int ValueDrop = array[i - k];
        int ValueAdd = array[i];

        sumaVentana = sumaVentana - ValueDrop + ValueAdd;
        cout << sumaVentana << " → " << array[i - k + 1] << " + " << array[i - k + 2] << " + " << array[i] << endl;
    }

}

int main() {
    vector<int> numeros = {1, 3, 5, 2, 8, 0, 1};
    int tamVentana = 3;

    MostrarVentanasConSuma(numeros, tamVentana);

    return 0;
}