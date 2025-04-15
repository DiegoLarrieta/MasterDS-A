/*
Ejercicio 2: Suma de elementos mayores que un valor dado
🎯 Enunciado:
Dado un vector y un número target, suma todos los elementos mayores que target.

Ejemplo:
Input:  [10, 5, 8, 20, 3], target = 7
Output: 10 + 8 + 20 = 38


*/

#include <iostream>
#include <vector>
using namespace std;

int SumGreaterThanTarget(vector<int> &nums , int target){
    int sum = 0;

    for(int i= 0; i < nums.size(); i++){
        if(nums[i] > target){
            sum += nums[i];
        }
    }
    return sum;
}

int main(){
    vector<int> nums = {10, 5, 8, 20, 3};
    int target = 7;
    int result = SumGreaterThanTarget(nums, target);
    cout << result << endl; // Output: 38
}