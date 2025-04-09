/*
Ejercicio 1: Encontrar si existe un par con suma igual al target (en vector ordenado)
🎯 Enunciado:
Dado un vector ordenado de forma creciente y un número target, determina si hay dos números en el vector cuya suma sea igual a target.

vector<int> v = {1, 2, 3, 4, 6};
target = 7;  // → true  (1 + 6 o 3 + 4)

target = 20; // → false (no hay combinación)

*/

#include <iostream>
#include <vector>
using namespace std;

bool FindPairWithSum(vector<int> &arr, int target){
    int left = 0;
    int right = arr.size()-1;

    while(left < right){
        int sum = arr[left] + arr[right];

        if(sum == target){
            return true;
        }

        // Si la suma es menor que target movemos el puntero izquiero a la derecha para aumentar el valor de la suma 

        else if( sum < target){
            left++;
        }
        // Si la suma es mayor que target movemos el puntero derecho a la izquierda para disminuir el valor de la suma
        else{
            right--;
        }
    }
    return false; // Si no encontramos ningún par que sume target

}

int main(){
    cout << boolalpha;
    vector<int> v = {1, 2, 3, 4, 6};
    int target = 7;

    cout << FindPairWithSum(v, target) << endl; // Debería imprimir true

    target = 20;
    cout << FindPairWithSum(v, target) << endl; // Debería imprimir false
}