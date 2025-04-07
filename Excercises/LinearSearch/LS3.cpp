/*
Enunciado:
Escribe una función que reciba un vector<int> y un número objetivo (target), y devuelva un nuevo vector con todos los elementos que sean múltiplos de ese número.

Si no hay ningún múltiplo, debe devolver un vector vacío.

vector<int> v = {7, 8, 10, 9, 33};
int target = 2;
Resultado: {8, 10} // porque son los únicos múltiplos de 2 en el vector
*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> FindAllMultiples(vector<int> arr, int target){
    vector<int> multiples;

    for(int i = 0 ; i < arr.size(); i++){

        if(arr[i] % target == 0){
            multiples.push_back(arr[i]);
        }
    }
    return multiples;
}

int main(){
    vector<int> v = {7, 8, 10, 9, 33};
    int target = 2;

    vector<int> result = FindAllMultiples(v, target);

    for(int num : result){
        cout << num << " ";
    }
    cout << endl; 

}
