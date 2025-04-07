#include <iostream>
#include <vector>

using namespace std;
// 1 2 3 4 5
int BinarySearch(vector<int> arr , int target){
    int inicio = 0;
    int fin = arr.size()-1;
    while(inicio <= fin){
        // Calcular la mitad
        int mitad = inicio + (fin - inicio) / 2;
        // Si el elemento en la mitad es el que buscamos, devolver el índice
        if(arr[mitad] == target){
            return mitad;
        }
        // Si es mayor buscamos a la derecha
        else if ( arr[mitad] < target){
            inicio = mitad + 1;
        }
        // Si es menor buscamos a la izquierda
        else{
            fin = mitad - 1;
        }

    }
    return -1;
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};

    cout<<BinarySearch(v, 3)<<endl; // Debería imprimir 2
    cout<<BinarySearch(v, 6)<<endl; // Debería imprimir -1
}