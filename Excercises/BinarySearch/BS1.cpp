/*
Dado un vector ordenado y un número target, 
devuelve true si el número existe en el vector, o false si no está.

vector<int> v = {1, 4, 7, 10, 13};
target = 10; // → true
target = 6;  // → false

*/

#include <iostream>
#include <vector>
using namespace std;
// 1 2 3 4 5 
bool BinarySeach(vector<int> arr , int target){
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){
        int half = start + (end - start)/2;

        if (arr[half] == target){
            return true;
        }

        else if ( arr[half] < target){
            start = half + 1;
        }
        else{
            end = half - 1;
        }
    }
    return false;
}

int main(){
    // para imprimir true o false de 0 o 1 
    cout << boolalpha;

    vector<int> v = {1, 4, 7, 10 , 13};

    cout<<BinarySeach(v, 10)<<endl; // Debería imprimir true
    cout<<BinarySeach(v, 6)<<endl; // Debería imprimir false
}