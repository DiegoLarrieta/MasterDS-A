/*
Ejercicio 5: Ventana con promedio más alto
🎯 Enunciado:
Devuelve el mayor promedio que puedes obtener entre las ventanas de tamaño k.

Solo necesitas hacer suma / k en cada ventana y comparar el promedio.

arr = {1, 3, 2, 6, -1, 4, 1, 8, 2}, k = 5
Output: 2.8

arr = {5, 5, 5, 5}, k = 2
Output : 5.0

*/

#include <iostream>
#include <vector>
using namespace std;



double SumPromedioWithWindow(const vector<int> &arr, int k){

    //Verificamos que la ventana no sea más grande que el arreglo
    int n = arr.size();
    if( k > n){
        return 0;
    }

    // Primera Ventana
    int sumWindow = 0;
 
    for(int i = 0; i < k ; i++){
        sumWindow += arr[i];
    }
    double maxAverage = (double)sumWindow / k;  // Primer promedio
    // Deslizamos la ventana
    for(int i =  k; i < n ; i++){
        int valueDrop = arr[i - k];
        int valueAdd = arr[i];

        sumWindow = sumWindow - valueDrop + valueAdd;

        double currentAverage = (double)sumWindow / k;

        if(currentAverage > maxAverage){
            maxAverage = currentAverage;
        }
    }
    return maxAverage;
}

int main() {
    vector<int> arr = {5,5,5,5};
    int k = 2;

    double resultado = SumPromedioWithWindow(arr, k);
    cout << "✅ Mayor promedio en ventana de tamaño " << k << ": " << resultado << endl;
}
