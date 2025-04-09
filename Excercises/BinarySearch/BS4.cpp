/*
Ejercicio 4: Encontrar el número más pequeño mayor o igual al target (Ceiling)
🎯 Enunciado:
Dado un vector ordenado en forma creciente y un target, encuentra el número más pequeño que sea mayor o igual al target.

Si no existe tal número, devuelve -1.

vector<int> v = {2, 3, 5, 7, 9};

FindCeiling(v, 4); // → 5
FindCeiling(v, 7); // → 7
FindCeiling(v, 10); // → -1 (no hay ninguno mayor o igual)

*/

#include <iostream>
#include <vector>
using namespace std;

int findCeiling(vector<int> arr, int target){
    int start = 0;
    int end = arr.size()-1;

    int result = -1;

    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == target){
            result = arr[mid];
            break; // Encontramos el número exacto
        }
        else if(arr[mid] < target){
            start = mid + 1;
        
        }
        else{
            result = arr[mid]; // Guardamos el resultado
            end = mid - 1; // Buscamos a la izquierda para encontrar el más pequeño
        }
    }
    return result; // Devolvemos el resultado

}

int main(){
    vector<int> v = {2, 3, 5, 7, 9};

    cout << findCeiling(v, 4) << endl; // Debería imprimir 5
    cout << findCeiling(v, 7) << endl; // Debería imprimir 7
    cout << findCeiling(v, 10) << endl; // Debería imprimir -1 (no hay ninguno mayor o igual)
}
