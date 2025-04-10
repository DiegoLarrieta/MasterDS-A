/*
Ejercicio 5 (versión adaptada): Eliminar todos los valores negativos de un vector
🎯 Enunciado:
Dado un vector de enteros, elimina todos los números negativos in-place, manteniendo el orden del resto.

Devuelve la nueva longitud del vector.

vector<int> v = {4, -2, 7, -5, 1};

Resultado esperado: [4, 7, 1, _, _] → longitud = 3

*/


#include <iostream>
#include <vector>
using namespace std;

int RemoveNegatives(vector<int> &arr){
    int escritor = 0;
    int explorador = 0;

    while(explorador < arr.size()){
        // Si el elemento es un numero positivo
        if(arr[explorador] >= 0){
            // Inserta el elemento en la posición del escritor
            arr[escritor] = arr[explorador];

            // Movemos el escritor a la derecha
            escritor++;
        }
        // En ambos casos, necesitamos mover el puntero a la derecha 
        explorador++;
    }
    return escritor; // Retornamos la longuitud
}

int main(){
    vector<int> v = {4, -2, 7, -5, 1};
    int newLength = RemoveNegatives(v);
    
    cout<<"Nueva longuitud: "<<newLength<<endl; // Debería imprimir: Nueva longitud: 3

    cout<<"Vector resultante: ";
    for(int i = 0; i < newLength; i++){
        cout<<v[i]<<" "; // Debería imprimir: 4 7 1
    }
    cout<<endl;

    // Imprimir el vector completo (incluyendo los elementos no relevantes)
    cout<<"Vector completo: ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" "; // Debería imprimir: 4 7 1 -5 -2 Recuerda que es porque lo pasamos por referencia entonces se modifica el original
    }
    cout<<endl;


    return 0;
}