/*
Enunciado:
Dado un vector de enteros y un número objetivo (target), encuentra el índice del número que esté más cerca del objetivo.
Si hay dos con la misma distancia, devuelve el primero que aparece.

vector<int> v = {1, 5, 10, 15, 20};
int target = 12;
Resultado esperado: 2  // Porque 10 está más cerca que 15

*/

#include <iostream>
#include <vector>
#include <limits.h> // Para INT_MAX
#include <cmath> // Para abs()
#include <algorithm> // Para std::abs
using namespace std;

int FindClosestIndex(vector<int> arr, int target){

    int closestindex = -1; // Inicializamos con -1 para indicar que no hemos encontrado un índice válido
    int closestdistance = INT_MAX; // Valor máximo posible para la distancia

    for(int i = 0 ; i < arr.size(); i++){
        int diff = abs(arr[i] - target); // Calculamos la distancia al objetivo

        // Si la distancia es menor que la más cercana encontrada hasta ahora
        
        if(diff < closestdistance){
            closestdistance = diff; // Actualizamos la distancia más cercana
            closestindex = i; // Actualizamos el índice más cercano
        }
    }
    return closestindex; // Devolvemos el índice del número más cercano al objetivo
}

int main(){
    vector<int> v = {1, 5, 10, 15, 20};
    int target = 12;

    int result = FindClosestIndex(v, target);
    cout << result << endl;
}