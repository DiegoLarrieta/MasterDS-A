/*
Ejercicio 8: ¿Existe un par con diferencia exacta igual a K?
🎯 Enunciado:
Dado un vector ordenado de forma creciente y un número k, determina si existe un par de elementos cuya diferencia absoluta sea igual a k.

Entrada: nums = {1, 3, 4, 6, 9}, k = 2  
Salida: true  // 3 y 1 ó 6 y 4

Entrada: nums = {1, 3, 4, 6, 9}, k = 5
Salida: true  


Entrada: nums = {1, 3, 4, 6, 9}, k = 7
Salida: false


*/

#include <iostream>
#include <vector>
using namespace std;

// Si el valor es mayor mover puntero high a la izquierda

bool FindPairWithDifferenceK(vector<int> &arr, int k){
    int low = 0;
    int high = arr.size()-1;

    while( low < high){
        int diff = arr[high] - arr[low];

        if(diff == k){
            return true;
        }
        else if(diff < k){
            low++;
        }else{
            high--;
        }
    }
    return false; // Si no encontramos ningún par que tenga la diferencia k
}
int main(){
    vector<int> v1 = {1, 3, 4, 6, 9};
    int k1 = 2;

    vector<int> v2 = {1, 3, 4, 6, 9};
    int k2 = 5;

    vector<int> v3 = {1, 3, 4, 6, 9};
    int k3 = 7;

    cout << boolalpha;
    cout << FindPairWithDifferenceK(v1, k1) << endl; // Debería imprimir true
    cout << FindPairWithDifferenceK(v2, k2) << endl; // Debería imprimir true
    cout << FindPairWithDifferenceK(v3, k3) << endl; // Debería imprimir false

    return 0;
}