/*
Ejercicio: Encontrar el valor máximo y mínimo en el subarreglos de tamaño k
🧠 Enunciado:
Dado un vector de enteros y un entero k, imprime el valor máximo y mínimo del subarreglo contiguo de tamaño k.

pair<int,int> MaxMinEnVentanas(const vector<int>& arr, int k);

arr = {4, 2, 12, 3, 8, 5}, k = 4

→ Ventana: {4, 2, 12, 3} → Máximo = 12, Mínimo = 2


*/
#include <iostream>
#include <vector>
using namespace std;

pair<int,int>MaxMinEnVetanas(vector<int>&arr, int k){
    int min = arr[0];
    int max = arr[0];

    // Recorremos el vector dentro del tamaño de la ventana
    for(int i = 0; i < k; i++){
        // Encontramos el maximo y minimo de la ventana
        if(arr[i] > max){
            max = arr[i];
        }

        if(arr[i] < min){
            min = arr[i];
        }
    }
    return {max, min};
}

int main(){
    vector<int> arr = {4, 2, 12, 3, 1, 5};
    int k = 5;
    pair<int, int> resultado = MaxMinEnVetanas(arr, k);

    cout << "Máximo: " << resultado.first << endl;
    cout << "Mínimo: " << resultado.second << endl;
}