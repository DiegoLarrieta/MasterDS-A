/*
Ejercicio 3: Suma en un subarreglo entre dos índices
🎯 Enunciado:
Dado un vector y dos índices inicio y fin, devuelve la suma de todos los elementos entre esos dos índices (inclusive).

Ejemplo:
Input:  [5, 2, 7, 4, 6], inicio = 1, fin = 3
Output: 2 + 7 + 4 = 13


*/

#include <iostream>
#include <vector>
using namespace std;

int SumInSubarray(vector<int> &arr, int start, int end){
    int sum = 0;
    // Validamos que los índices estén dentro del rango del vector
    if(start < 0 || end >= arr.size() || start > end){
        cout << "Índices fuera de rango" << endl;
        return -1; // Indicamos un error
    }
    // Recorremos el subarreglo desde start hasta end
    for(int i = start; i <= end; i++){
        sum += arr[i];
    }
    return sum; // Devolvemos la suma del subarreglo

}

int main(){
    vector<int> arr = {5, 2, 7, 4, 6};
    int start = 1;
    int end = 3;
    int result = SumInSubarray(arr, start, end);
    cout << result << endl; // Output: 13
}