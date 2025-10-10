// Leetcode 643 - Maximum Average Subarray I

#include <iostream>
#include <vector>

using namespace std;
// O(n) time complexity and O(1) space complexity
//O(1) its because we 
double findMaxAverage(vector<int> &nums, int k){
    // Paso default. Si la ventana es mayor al arreglo, retornamos 0
    if(k > nums.size()) return 0.0;

    // Paso 1. Crear varible para maxAverge y sum
    double maxAverage = 0.0;
    double sum = 0.0;

    // Paso 2. Calcular la suma de la primera ventana
    for(int i = 0; i < k ; i++){
        sum += nums[i];
    }
    maxAverage = sum / k;

    // Paso 3. Deslizar la ventana por el arreglo
    for(int i = k ; i < nums.size(); i++){
        // Aumentamos la suma con el nuevo elemento que entra a la ventana
        sum += nums[i];

        // Reducimos la suma con el elemento que sale de la ventana
        sum -= nums[i - k];

        // Calculamos el promedio actual
        double currentAverage = sum / k;
        // Actualizamos el maxAverage si el promedio actual es mayor
        maxAverage = max(maxAverage, currentAverage);
    }

    return maxAverage;

}
