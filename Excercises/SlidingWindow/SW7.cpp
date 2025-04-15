/*
Ejercicio fácil: Subarreglo más largo con suma menor o igual a target
🎯 Enunciado:
Dado un arreglo de números positivos y un número target, encuentra la longitud 
máxima de un subarreglo continuo cuya suma total sea menor o igual a target.

arr = [1, 2, 1, 0, 1, 1, 1], target = 4

Ventanas válidas:
[1, 2, 1] → suma = 4 → ✅ longitud = 3

[2, 1, 0, 1] → suma = 4 → ✅ longitud = 4 

[1, 0, 1, 1, 1] → suma = 4 → ✅ longitud = 5

✔️ Resultado esperado: 4
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int longestSubArrayLesserTarget(const vector<int> &array, int target){
    int start = 0;
    int sum = 0;
    int maxLenght = 0;
    // Recorremos el puntero end para ir agrandando el valor de la longuitud 
    for(int end = 0; end < array.size(); end++){

        sum += array[end];

        while( sum > target ){
            sum = sum - array[start];
            start++;
        }
        // Aquí la suma ya es válida (<= target)
        int windowSize = end - start + 1;
        if(windowSize > maxLenght){
            maxLenght = windowSize;
        }
    }
    return maxLenght;
}

int main(){
    vector<int> array = {1, 2, 1, 0, 1, 1, 1};
    int target = 4;

   int result = longestSubArrayLesserTarget(array, target);

   cout<<result<<endl;
}
