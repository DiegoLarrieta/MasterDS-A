/*
Escribe una función que reciba un vector de enteros y un número objetivo (target).
Tu función debe devolver el primer número del vector que sea mayor al objetivo.
Si no hay ninguno, devuelve -1.

Ejemplo:
vector<int> v = {3, 7, 2, 9, 4};
target = 5;

Resultado: 7  // porque es el primer número mayor que 5


*/

#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(vector<int> arr, int target){
    for(int i = 0; i < arr.size(); i++){
        // Si el valor actual es mayor al que buscamos, devolver el número
        if(arr[i] > target){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    vector<int> v = {3, 7, 2, 9, 4};
    int target = 5;

    int result = LinearSearch(v, target);
    cout<<result<<endl;
}