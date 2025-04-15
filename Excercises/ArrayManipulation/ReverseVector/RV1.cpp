/*
Ejercicio 1: Reversa de un subarreglo entre dos índices
🧠 Enunciado:
Dado un vector y dos índices i y j, invierte los elementos entre esas posiciones inclusive, dejando el resto igual.


Input:  nums = [1, 2, 3, 4, 5], i = 1, j = 3
Output: [1, 4, 3, 2, 5]

*/

#include <iostream>
#include <vector>
using namespace std;

void ReverseSubarray(vector<int> &arr, int i, int j){
    
    while(i < j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    int i = 1;
    int j = 3;

    ReverseSubarray(v, i, j);
    
    cout << "Vector invertido: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " "; // Debería imprimir: 1 4 3 2 5
    }
    cout << endl;

    return 0;
}

