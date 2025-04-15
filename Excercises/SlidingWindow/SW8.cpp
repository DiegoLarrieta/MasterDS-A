/*
Ejercicio: Longest Subarray with Sum Exactly Equal to Target
🎯 Enunciado:
Dado un arreglo de enteros positivos y un número target, encuentra la longitud 
del subarreglo continuo más largo cuya suma sea exactamente igual al target.

arr = {1, 2, 1, 1, 1}
target = 3
Subarreglo [1, 2] → suma = 3 → longitud = 2
Subarreglo [2 , 1] -> suma = 3 -> longuitud = 2
Subarreglo [1, 1, 1] → suma = 3 → longitud = 3 ✅
Resultado esperado: 3
*/

#include <iostream>
#include <vector>

using namespace std;

int longestSubarrayEqualTarget(const vector<int> &array, int target){
    // Var to calculate the sum of the elements in the array
    int sum = 0;

    // Initial pointer at the first index of the array
    int start = 0;

    // Var to calculate our max lenght
    int maxLengt = 0;

    for(int end = 0; end < array.size(); end++){
        sum += array[end];

        while(sum > target){
            sum = sum - array[start];
            start++;
        }

        if(sum == target){
            int windowSize = end - start + 1;
            if(windowSize > maxLengt){
                maxLengt = windowSize;
            }
        }

    }
    return maxLengt;
}   

int main(){
    vector<int>array = {1, 2, 1, 1, 1};
    int target = 3;

    int result = longestSubarrayEqualTarget(array, target);
    cout<<result<<endl;
    
}