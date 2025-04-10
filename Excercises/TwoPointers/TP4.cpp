/*
Ejercicio 4: Eliminar todas las apariciones de un número dado en un vector
🎯 Enunciado:
Dado un vector de enteros y un número target, elimina todas las apariciones de ese número in-place, y devuelve la nueva longitud del vector.

Los elementos que queden al final no importan.

vector<int> v = {3, 2, 2, 3};
target = 3;

Resultado: [2, 2, _, _], longitud = 2

*/

/*
Debug

°
*
3 2 2 3 -> Ambos punteros comienzan en 1 Los valores son iguales entonces muevo el puntero de explorador a la derecha

° *
3 2 2 3 -> Aqui el  puntero explorador(2) es diferente al target (3), entonces copiamos el valor de de la posicion explorador a escritor y lo movemos a la derecha 

  ° *
2 2 2 3 -> Aqui el puntero explorador(2) es diferente al target (3), entonces copiamos el valor de de la posicion explorador a escritor y lo movemos a la derecha 

    ° *
2 2 2 3 -> Aqui el puntero explorador(3) es igual al target (3), entonces solo movemos el puntero explorador a la derecha y salimos del while 

      
*/

#include <iostream>
#include <vector>
using namespace std;

int RemoveTarget(vector<int> & arr, int target){
    int escritor = 0;
    int explorador = 0;

    while(explorador < arr.size()){
        // Si el elemento en explorador es diferente != al target 
        if(arr[explorador] != target){
            // Lo moves a la posicion del escritor
            arr[escritor] = arr[explorador];
            escritor++;
        }
        // En ambos casos debemos de mover el explorador
        explorador++;
    }
    return escritor; // Retornamos la nueva longitud del vector   
}


int main(){
    vector<int> v = {3, 2, 2, 3};
    int target = 3;
    int newLength = RemoveTarget(v, target);
    
    cout << "Nueva longitud: " << newLength << endl; // Debería imprimir: Nueva longitud: 2
    cout << "Vector sin el target: ";
    for(int i = 0; i < newLength; i++){
        cout << v[i] << " "; // Debería imprimir: 2 2
    }
    cout << endl; // Para un salto de línea al final

    return 0;
}

