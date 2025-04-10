/*
Ejercicio 6: Quitar ceros repetidos (dejar solo uno)
🎯 Enunciado:
Dado un vector de enteros, elimina todos los ceros repetidos, dejando solo un cero si hay varios.

El resto de los números se mantienen en el mismo orden.

Entrada:  [1, 0, 0, 2, 3, 0, 0, 4]
Salida:   [1, 0, 2, 3, 4, _, _, _]
Longitud devuelta: 5

*/


#include <iostream>
#include <vector>
using namespace std;

int RemoveRepeatedZeros(vector<int>& arr) {
    int escritor = 0;
    bool zeroFound = false;

    for (int explorador = 0; explorador < arr.size(); explorador++) {
        if (arr[explorador] == 0 && !zeroFound) {
            arr[escritor++] = arr[explorador];
            zeroFound = true;
        } else if (arr[explorador] != 0) {
            arr[escritor++] = arr[explorador];
        }
        // Si encontramos un segundo cero, simplemente lo ignoramos
    }

    return escritor;
}


int main(){
    vector<int> v = {1, 0, 0, 2, 3, 0, 0, 4};
    int newLength = RemoveRepeatedZeros(v);
    
    cout<<"Nueva longitud: "<<newLength<<endl; // Debería imprimir: Nueva longitud: 5

    cout<<"Vector resultante: ";
    for(int i = 0; i < newLength; i++){
        cout<<v[i]<<" "; // Debería imprimir: 1 0 2 3 4
    }
    cout<<endl;

    return 0;
}