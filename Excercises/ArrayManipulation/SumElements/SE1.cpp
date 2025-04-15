/*
Ejercicio 1: Suma de números pares
🎯 Enunciado:
Dado un vector de enteros, devuelve la suma de todos los números pares.

Input:  [1, 2, 3, 4, 5, 6]
Output: 12  // (2 + 4 + 6)


*/


#include <iostream>
#include <vector>
using namespace std;

int SumPairs(vector<int>&nums){
    int sum = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % 2 == 0){
            sum += nums[i];
        }
    }
    return sum;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6};
    int result = SumPairs(nums);
    cout<<result<<endl;
}