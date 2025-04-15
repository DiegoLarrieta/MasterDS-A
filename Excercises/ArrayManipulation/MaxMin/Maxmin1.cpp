/*
Ejercicio: Encontrar el máximo y mínimo en un subarreglo
🧠 Enunciado:
Dado un vector de enteros y dos índices inicio y fin, encuentra el máximo y el mínimo valor dentro de ese rango, 
incluyendo ambos extremos.

pair<int, int> MaxMinSubarreglo(const vector<int>& arr, int inicio, int fin);

vector<int> nums = {4, 9, 1, 7, 3, 10, 2};
inicio = 2;
fin = 5;
🎯 Resultado esperado:
Subarreglo = {1, 7, 3, 10}
→ Máximo = 10
→ Mínimo = 1
*/

#include <iostream>
#include <vector>
using namespace std;

pair<int, int >MaxMinSubarray(const vector<int> &arr, int inicio, int fin){
    // Inicializamos maximo y minimo con el primer valor del subarreglo
    int max = arr[inicio];
    int min = arr[inicio];

    // Recorremos el subarreglo desde el indice inicio hasta fin
    for(int i = 0; i < arr.size(); i++){
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
    vector<int> nums = {4, 9, 1, 7, 3, 10, 2};
    int inicio = 2;
    int fin = 5;

    pair<int, int> resultado = MaxMinSubarray(nums, inicio, fin);
    cout << "Máximo: " << resultado.first << endl;
    cout << "Mínimo: " << resultado.second << endl;



    
}