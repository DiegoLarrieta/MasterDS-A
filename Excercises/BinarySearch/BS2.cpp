/*
Dado un vector ordenado y un número target, devuelve la posición donde debería insertarse ese número para que el vector siga ordenado.

Si el número ya está en el vector, devuelve su índice.

Si no está, devuelve el índice donde debería insertarse.

vector<int> v = {1, 3, 5, 6};

target = 5;  // → 2  (ya está)
target = 2;  // → 1  (debería ir entre 1 y 3)
target = 7;  // → 4  (al final)
target = 0;  // → 0  (al inicio)


*/

#include <iostream>
#include <vector>
using namespace std;

int BinarySearchInserPosition(vector<int> arr, int target){
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){
        int half = start + (end - start)/2;
        if(arr[half] == target){
            return half;
        }

        else if ( arr[half] < target){
            start = half + 1;
        }

        else{
            end = half - 1;
        }
    }
    return start;
}

int main(){
    vector<int> v = {1, 3, 5, 6};

    cout << BinarySearchInserPosition(v, 5) << endl; // Debería imprimir 2
    cout << BinarySearchInserPosition(v, 2) << endl; // Debería imprimir 1
    cout << BinarySearchInserPosition(v, 7) << endl; // Debería imprimir 4
    cout << BinarySearchInserPosition(v, 0) << endl; // Debería imprimir 0

}