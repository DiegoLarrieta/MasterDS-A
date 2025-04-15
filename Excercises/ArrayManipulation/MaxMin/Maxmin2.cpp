/*
Ejercicio: Diferencia máxima sin importar el orden
🧠 Enunciado:
Dado un vector de enteros, encuentra la máxima diferencia posible entre cualquier par de elementos,
sin importar su posición en el arreglo (es decir, arr[j] - arr[i] aunque j < i está permitido).

int MaximaDiferencia(const vector<int>& arr);

vector<int> nums = {2, 3, 10, 6, 4, 8, 1};
→ Diferencia máxima: 10 - 1 = 9

*/

#include <iostream>
#include <vector>

using namespace std;

int MaximaDiferencia(vector<int>& arr){
    // Inicializamos ambos valores con el primer elemento
    int max = arr[0];
    int min = arr[0];

    // Recorremos el vector para encontrar el maximo y minimo real

    for(int i = 0; i < arr.size(); i++){
        //Condicion para encontrar el maximo 
        if(arr[i] > max){
            max = arr[i];
        }
        //Condicion para encontrar el minimo
        if(arr[i] < min){
            min = arr[i];
        }
    }

    // Retornamos la diferencia entre el maximo y el minimo
    return max - min;
}

int main(){
    vector<int> nums = {2, 3, 10, 6, 4, 8 , 1};
    int resultado = MaximaDiferencia(nums);
    cout<<resultado<<endl;
}

