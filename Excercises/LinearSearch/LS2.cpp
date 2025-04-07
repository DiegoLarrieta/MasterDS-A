/*
Escribe una función en C++ que, dado un vector de enteros y un número objetivo (target), devuelva el primer número del vector que sea múltiplo de ese objetivo.
Si no existe ningún múltiplo, devuelve -1.

vector<int> v = {5, 8, 13, 20, 33};
int target = 4;


*/

#include <iostream>
#include <vector>
using namespace std;

int FindFirstMultiple(vector<int> arr, int target){
    for(int i= 0; i < arr.size();i++){
        // Si el valor actual es múltiplo del que buscamos, devolver el número
        if(arr[i] % target == 0){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    vector<int> v = {7, 8, 10, 9, 33};
    int target = 2;

    int result = FindFirstMultiple(v, target);
    cout<<result<<endl; // Debería imprimir 8 porque es el primer múltiplo de 4 en el vector
}
