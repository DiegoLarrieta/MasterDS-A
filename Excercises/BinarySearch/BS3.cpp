/*
🎯 Enunciado:
Dado un vector ordenado (puede contener elementos repetidos) y un target, encuentra el índice de su primera aparición.

vector<int> v = {1, 2, 2, 2, 3, 4, 5};
target = 2; // → 1 (primer índice donde aparece el 2)

*/
#include <iostream>
#include <vector>
using namespace std;

int BinarySearchFirstOccurence(vector<int> arr , int target){
    int start = 0;
    int end = arr.size()-1;

    int result = -1; // Inicializamos el resultado como -1 (no encontrado)

    while( start <= end){
        int half = start + (end - start)/2;

        if(arr[half] == target){
            result = half;
            end = half - 1; // Buscamos en la parte izquierda para encontrar la primera aparición
        }
        else if( arr[half] < target){
            start = half + 1; // Buscamos a la derecha
        }
        else{
            end = half - 1; // Buscamos a la izquierda
        }
    }
    return result; // Devolvemos el índice de la primera aparición o -1 si no se encontró
}

int main(){
    vector<int> v = {1, 2, 2, 2, 3, 4, 5};

    cout << BinarySearchFirstOccurence(v, 2) << endl; // Debería imprimir 1
    cout << BinarySearchFirstOccurence(v, 3) << endl; // Debería imprimir 4
    cout << BinarySearchFirstOccurence(v, 6) << endl; // Debería imprimir -1 (no encontrado)
}