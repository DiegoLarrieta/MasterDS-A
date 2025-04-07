/*
Suma de todos los múltiplos de un número
Enunciado:
Encuentra la suma total de todos los elementos en el vector que sean múltiplos de un número dado (target).

vector<int> v = {3, 6, 9, 10};
target = 3;
Resultado: 18 (3 + 6 + 9)

*/

#include <iostream>
#include <vector>
using namespace std;

int SumOfMultiples(vector<int> arr, int target){
    int sum = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % target == 0){
            sum += arr[i];
        }
    }
    return sum;
}

int main(){
    vector<int> v = {3, 6, 9, 10};
    int target = 3;
    int result = SumOfMultiples(v, target);
    cout << result << endl; 
}