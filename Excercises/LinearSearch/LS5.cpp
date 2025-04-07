/*
Contar cuántos elementos cumplen una condición
Enunciado:
Cuenta cuántos números en el vector son mayores que el valor objetivo (target).

vector<int> v = {3, 7, 2, 9, 4};
int target = 5;
Resultado: 2 // (7 y 9)

*/

#include <iostream>
#include <vector>
using namespace std;

int CountGreaterThanTarget(vector<int> arr, int target){
    int count = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > target){
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> v = {3, 7, 2, 9, 4};
    int target = 5;

    int result = CountGreaterThanTarget(v, target);
    cout << result << endl;
}