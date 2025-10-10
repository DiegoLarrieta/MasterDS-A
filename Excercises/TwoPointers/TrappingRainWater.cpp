// Leetcode 42 Trapping Rain Water HARD

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

int trap(vector<int> &height){
    // Obtener el size del vector 
    int n = height.size();

    // Crear 2 variables para almacenar el maximo de la izquierda y la derecha 
    vector<int> maxLeft(n,0);
    vector<int> maxRight(n,0);

    
    int lWall = 0;
    int rWall = 0;

    for(int i = 0; i < n; i++){
        int j = n - 1 - i; // Indice para recorrer desde la derecha

        // Actualizar el maximo de la izquierda
        maxLeft[i] = lWall;
        maxRight[j] = rWall;

        // Actualizar las paredes
        lWall = max(lWall, height[i]);
        rWall = max(rWall, height[j]);
    }

    int sum = 0;
    for(int i = 0; i < n ; i++){
        // Calcular el agua atrapada en la posicion i
        int potentialWater  = min(maxLeft[i], maxRight[i]);
        sum += max(0, potentialWater - height[i]); // Si es negativo no se añade nada
    }

    return sum;     
}