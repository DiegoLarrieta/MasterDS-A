// LeetCode 1

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// Complejidad O(N) donde N es el tamaño del array de entrada
vector<int> twoSum(vector<int> &nums, int target){
    // Create a hashmap to store the value and its index
    unordered_map<int, int> numMap;

    // Traverse the array
    for(int i = 0; i < nums.size(); i++){
        // Calculamos el complemento , es decir el valor que necesitamos para llegar al target
        int complement = target - nums[i];

        // Revisamos si el complemento ya lo hemos visto en el mapa
        if(numMap.find(complement) != numMap.end()){
            // Si ya lo hemos visto , retornamos los indices 
            return {numMap[complement], i};
        }

        // Si no hemos visto el complemento, agregamos el numero actual al mapa con su indice
        // Agregamos 2 al mapa con su indice 0 , numMap = {2:0}

        numMap[nums[i]] = i;
    }
    // Si no encontramos ninguna pareja que sume el target, retornamos un array vacio
    return {};
}