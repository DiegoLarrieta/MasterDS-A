// Leetcode 15 3Sum

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){
    // Sort the array to make it easier to avoid duplicates and use two pointers
    sort(nums.begin(), nums.end());

    // Create the result vector
    vector<vector<int>> result;

    // Loop through the array
    for(int i = 0 ; i < nums.size(); i++){
        // Como el array esta ordenado , al momento en el que i sea mayor a 0 , significa quue nunca daremos con el resultado
        // ya que los siguientes numeros tambien son positivos
        if(nums[i] > 0) break;

        // Para evitar duplicados en la salida 
        // Si i es igual al anterior significa que ya hemos considerado ese numero como punto de partida
        // continuamos lo cual significa que saltamos este numero
        if(i > 0 && nums[i] == nums[i-1]) continue;

        // Declare the high and low pointers
        int low = i + 1; // Points to the next element after i
        int high = nums.size()-1;
        

        while( low < high ){
            int sum = nums[i] + nums[low] + nums[high];

            // Si la suma es menos que 0 , necesitamos aumentar la suma-> moover el puntero low
            if(sum < 0){
                low++;
            }
            // Si la suma es mayor que cero , necesitamos reducir la suma -> disminuir high
            else if(sum > 0){
                high--;
            }
            // Si la suma es 0
            else{
                // Si la suma es 0 , hemos encontrado un triplete
                // Lo agregamos al resultado
                result.push_back({nums[i], nums[low],nums[high]});

                // Ahora necesitamos mover ambos punteros para buscar otros posibles tripletes
                low++;
                high--;
                // Evitar duplicados en low
                while(low < high && nums[low] == nums[low - 1]) low++; // Si el nuevo low es igual al anterior, mover low
                // Evitar duplicados en high
                while(low < high && nums[high] == nums[high + 1]) high--; // Si el nuevo high es igual al anterior, mover high
            }
        }
    }
    return result;
}