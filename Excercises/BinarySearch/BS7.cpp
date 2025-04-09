/*
🎯 Ejercicio 7: Mínimo en arreglo rotado
Enunciado:
Dado un vector rotado creciente (como si rotaras un array ordenado), encuentra el valor mínimo.

El vector no tiene elementos repetidos.

vector<int> v = {4, 5, 6, 7, 0, 1, 2}; → 0  
vector<int> v = {3, 4, 5, 1, 2};       → 1  
vector<int> v = {1, 2, 3, 4, 5};       → 1  (no rotado)  


*/

#include <iostream>
#include <vector>
using namespace std;

int FindMin(vector<int> arr){
    int start = 0;
    int end =  arr.size()-1;

    while(start <= end){
        int mid = start + ( end - start) / 2;
        // Si el elemento de la mitad es menor que el siguiente, significa que estamos en la parte ascendente
        if(arr[mid] < arr[mid + 1]){
            end = mid - 1;
        }
        else{
            start = mid + 1; // Buscamos en la parte derecha
        }
    }
    return arr[start]; // Devolvemos el elemento mínimo
}

int main(){
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    vector<int> v2 = {3, 4, 5, 1, 2};
    vector<int> v3 = {1, 2, 3, 4, 5};
    cout << FindMin(v) << endl; // Debería imprimir 0
    cout << FindMin(v2) << endl; // Debería imprimir 1
    cout<< FindMin(v3) << endl; // Debería imprimir 1 (último elemento)
    return 0;
}