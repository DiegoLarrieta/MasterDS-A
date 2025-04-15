/*
Ejercicio 4: Suma acumulativa
🎯 Enunciado:
Dado un vector, devuelve un nuevo vector donde cada posición contenga la suma de todos los elementos hasta ese punto.
Input:  [1, 2, 3, 4]
Output: [1, 3, 6, 10]


*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> SumaAcumulativa(const vector<int> &arr){
    vector<int> resultado;
    int suma = 0;
    // Recorremos cada elemento del vector
    for(int i= 0; i < arr.size();i++){
        suma += arr[i];
        resultado.push_back(suma);
    }
    return resultado; // Devolvemos el vector con la suma acumulativa
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    vector<int> resultado = SumaAcumulativa(arr);
    // Imprimimos el resultado
    for(int i=0; i < resultado.size(); i++){
        cout << resultado[i] << " ";
    }
    cout << endl; // Output: 1 3 6 10
}