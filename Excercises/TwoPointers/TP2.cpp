/*
Ejercicio 2: Mover todos los ceros al final del vector (manteniendo el orden)
🎯 Enunciado:
Dado un vector de enteros, mueve todos los ceros al final del vector, manteniendo el orden relativo de los elementos no cero.

La operación debe hacerse in-place (sin usar un vector adicional).

Entrada:  [0, 1, 0, 3, 12]  
Salida:   [1, 3, 12, 0, 0]

*/

#include <iostream>
#include <vector>
using namespace std;

void MoverCeros(vector<int>& arr){
    int pos = 0;
    int pointermovespos = 0;
    while(pointermovespos < arr.size()){
        if(arr[pointermovespos] != 0){
            arr[pos] = arr[pointermovespos];
            pos++;
        }
        pointermovespos++;
    }
    // Rellenar el resto del vector con ceros
    while(pos < arr.size()){
        arr[pos] = 0;
        pos++;
    }
}

int main(){
    vector<int> v = {0, 1, 0, 3, 12};
    MoverCeros(v);
    for(int i : v){
        cout << i << " ";
    }
    cout << endl; // Debería imprimir: 1 3 12 0 0
}
