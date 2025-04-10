/*
Ejercicio 7: Encontrar si existe un par con suma igual al target (en vector ordenado)
🎯 Enunciado:
Dado un vector ordenado de forma creciente y un número target, determina si hay dos números en el vector cuya suma sea igual a target.

Input nums = {1, 2, 3, 4, 6};
target = 7;  // 
output [0 4]

Input: nums = [3,3], 
target = 6
Output: [0,1]

Input: nums [-5, -2, 0, 3, 6, 10], 
target = 4
Output: [1,4]
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> FindPairWithSum(vector<int> &arr, int target){
    vector<int> result;

    int low = 0;
    int high = arr.size()-1;

    while(low < high){
        int sum = arr[low] + arr[high];

        if(sum == target){
            result.push_back(low);
            result.push_back(high);
            return result;
        }
        else if(sum < target){
            low++;
        }else{
            high--;
        }
    }
    return result;
}

int main(){
    vector<int> v1 = {1, 2, 3, 4, 6};
    int target1 = 7;

    vector<int> v2 = {3, 3};
    int target2 = 6;

    vector<int> v3 = {-5, -2, 0, 3, 6, 10};
    int target3 = 4;

    vector<int> result1 = FindPairWithSum(v1, target1);
    vector<int> result2 = FindPairWithSum(v2, target2);
    vector<int> result3 = FindPairWithSum(v3, target3);
    cout<<result1[0]<<" "<<result1[1]<<endl;
    cout<<result2[0]<<" "<<result2[1]<<endl;
    cout<<result3[0]<<" "<<result3[1]<<endl;

}
