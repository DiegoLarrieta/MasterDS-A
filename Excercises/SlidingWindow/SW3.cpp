/*
Ejercicio 3: Contar cuántas ventanas tienen suma > target
🎯 Enunciado:
Dado un vector, un k, y un valor objetivo (target), cuenta cuántas ventanas de tamaño k tienen una suma estrictamente mayor que target.

Ejemplo:


arr = {1, 4, 2, 10, 23, 3, 1, 0, 20}, k = 4, target = 20  
Output: 5  // Hay 5 ventanas con suma > 20
*/

#include <iostream>
#include <vector>
using namespace std;

int ContarVentanasconSumaMayor(const vector<int> &array, int k , int target){
    // Variable to calculate the size of the array
    int n = array.size();

    // Validate that the window size is not larger than the array
    if(k > n){
        cout << "Error, the window is larger"<<endl;
        return 0;
    }

    // Calculate the first window
    int numberWindowsGreater = 0;
    int sumWindow = 0;

    for(int i = 0; i < k; i++){
        sumWindow += array[i];
        
        if(sumWindow > target){
            numberWindowsGreater++;
        }
    }

    // Slide the window
    for(int i = k ; i < n; i++){
        int valueDrop = array[i - k];
        int valueAdd = array[i];

        sumWindow = sumWindow - valueDrop + valueAdd;

        if(sumWindow > target){
            numberWindowsGreater++;
        }
    }
    return numberWindowsGreater;
}

int main(){
    vector<int> numbers = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int windowSize = 4;
    int target = 20;

    int result = ContarVentanasconSumaMayor(numbers, windowSize, target);

    cout << result << endl;

    return 0;
}

