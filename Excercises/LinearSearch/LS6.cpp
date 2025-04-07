/*
Encontrar el primer número mayor y el primero menor al target
Enunciado:
Devuelve dos valores:

El primer número mayor al target.

El primer número menor al target.

vector<int> v = {3, 7, 2, 9, 4};
int target = 6;
Resultado: mayor → 7, menor → 3


*/

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> FindMaxMin(vector<int> arr , int target){
    int firstGreater = -1;// Inicializamos con -1 para indicar que no hemos encontrado un número mayor
    int firstLesser = -1; // Inicializamos con -1 para indicar que no hemos encontrado un número menor
    for(int i  = 0; i < arr.size(); i++){
        if(arr[i] > target && firstGreater == -1){
            firstGreater = arr[i];
            
        }
        if(arr[i] < target && firstLesser == -1){
            firstLesser = arr[i];
            
        }
    }
    return make_pair(firstGreater, firstLesser);

}


int main(){
    vector<int> v = {3, 7, 2, 9, 4};
    int target = 6;

    // Llamamos a la función y guardamos el resultado
    pair<int, int> resultado = FindMaxMin(v, target);

    // Accedemos a los valores del par con .first y .second
    cout << resultado.first << "   " << resultado.second << endl; 

    return 0;
}

