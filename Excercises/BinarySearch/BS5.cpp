/*
🕳️ Ejercicio 5: Buscar el pico en una montaña (peak element)
🎯 Enunciado:
Dado un vector de enteros que primero sube y luego baja (forma de montaña), encuentra el índice del pico, es decir, el número más grande.

Se garantiza que el pico no está en los extremos y el arreglo tiene al menos 3 elementos.

vector<int> v = {1, 3, 5, 7, 6, 4, 2};
Resultado: 3  // arr[3] = 7 es el pico

{2 4 6 8 9 7 5 3 1}

*/

#include <iostream>
#include <vector>
using namespace std;

int FindPeakElement(vector<int> arr){
    int start = 0;
    int end =  arr.size()-1;

    while(start < end){
        int mid = start + (end - start ) / 2;
        // Si el elemento de la mitad es mayor que el siguiente, significa que estamos en la parte ascendente
        if(arr[mid] > arr[mid + 1]){
            end = mid; // Buscamos en la parte izquierda
        }
        else{
            start = mid + 1; // Buscamos en la parte derecha
        }
    }
    return start;
}

int main(){
    vector<int> v = {1, 3, 5, 7, 6, 4, 2};
    vector<int> v2 = {2, 4, 6, 8, 9, 7, 5, 3, 1};
    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << FindPeakElement(v) << endl; // Debería imprimir 3
    cout << FindPeakElement(v2) << endl; // Debería imprimir 4
    cout<< FindPeakElement(v3) << endl; // Debería imprimir 8 (último elemento)
    return 0;
}