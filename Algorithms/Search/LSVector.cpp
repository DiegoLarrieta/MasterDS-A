#include <iostream>
#include <vector>

using namespace std;

// Paso 1: Recorrer el vector
int LinearSearch(vector<int> arr , int target){
    for(int i = 0; i < arr.size();i++){
        // Paso 2: Si el valor actual es igual al que buscamos, devolver el índice
        if(arr[i] == target){
            return i;
        }
    }
    // Paso 3: Si terminamos el for y no lo encontramos, devolver -1
    return -1;
}



