/*
Ejercicio 3: Rotar un array a la derecha por k posiciones
🧠 Enunciado:
Dado un vector, rota sus elementos a la derecha k veces.
Hazlo in-place usando el algoritmo de reverse.

Input:  nums = [1, 2, 3, 4, 5, 6, 7], k = 3
Output: [5, 6, 7, 1, 2, 3, 4]

Paso 1 : Reversa el vector completo
[1, 2, 3, 4, 5, 6, 7] → [7, 6, 5, 4, 3, 2, 1]

Paso 2 : Reversa los primeros k elementos
[7, 6, 5] → [5, 6, 7]
→ [5, 6, 7, 4, 3, 2, 1]

Paso 3 : Reversa el resto del vector
[4, 3, 2, 1] → [1, 2, 3, 4]
→ [5, 6, 7, 1, 2, 3, 4]



*/

#include <iostream>
#include <vector>
using namespace std;

void ReverseVector(vector<int> &arr, int k){
    int low = 0;
    int high = arr.size()-1;


    if(k > arr.size()){
        k = k % arr.size();
    }

    // Reverse the entire array
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }

    // Reverse the first k elements
    low = 0;
    high = k -1; // based index;

    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }

    // Reverse the rest of the array
    low  = k ; // que comeince desde la posicion en la que se quedo 
    high = arr.size()-1;
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
    
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    ReverseVector(v, k);
    cout<<"Vector rotado: ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}