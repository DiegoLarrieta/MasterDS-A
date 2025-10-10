#include <iostream>
#include <vector>
// import for min function
#include <algorithm>
#include <climits>

using namespace std;
// O(n) time complexity
// O(1) space complexity
int minSubArrayLen(int target, vector<int> &nums){
    // Paso 1 - Inicializar variable para calcular la suma y el size 
    int sum = 0;
    int minSize = INT_MAX;

    // Paso 2. Inicializar el puntero left
    int left = 0;

    // Paso 3. Iterar a traves del array con el puntero right
    for(int right = 0 ; right < nums.size() ; right++){
        // Agregar el valor en la posicion right a la suma
        sum += nums[right];

        // Si la suma es mayor o igual que target, vamos a mover left a la derecha
        while(sum >= target){
            // Calcular el size de esta ventana
            minSize = min(minSize, right - left + 1);
            // Restamos el valor que pasamos al mover left
            sum -= nums[left];
            // Mover left a la derecha
            left++;
        }    
    }
    // Si minSize no ha cambiado, significa que no encontramos ninguna subarray valida , asi que retornamos 0
    return minSize == INT_MAX ? 0 : minSize;

}