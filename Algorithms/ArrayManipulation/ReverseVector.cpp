/*
Darle reverse a un vector 
Entrada:  [1, 2, 3, 4, 5]
Salida:   [5, 4, 3, 2, 1]

*/

#include <iostream>
#include <vector>
using namespace std;

void ReverseVector(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    ReverseVector(v);
    
    cout << "Vector invertido: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " "; // Debería imprimir: 5 4 3 2 1
    }
    cout << endl;

    return 0;
}