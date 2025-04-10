/*
Ejercicio 10: Mover todos los elementos distintos de X al frente
🎯 Enunciado:
Dado un vector de enteros y un número x, mueve todos los elementos distintos de x al frente del vector, manteniendo su orden relativo.
Hazlo in-place y devuelve la nueva longitud.
Entrada:  [3, 1, 3, 2, 4, 3], x = 3  
Salida:   [1, 2, 4, _, _, _], longitud: 3

Inicial
Ambos punteros estan en el 3, como == x , avanzamos el fast al 1, y ahora asignamos el low == fast , por lo que queda 1 1
3 1 3 2 4 3

Iteracion 1
Ya que quedo la asignacion movemos el low a la derecha y el high tambien , ahora low esta en la pos 1 y high en el [2]
1 1 3 2 4 3

Iteacion 3
Como high encontro un 3 copiamos su valor a low == fast
  °   *
1 2 3 2 4 3

Iteacion 4
Ya que esta movemos ambos punteros a la derecha y como high esta en 4 se mueve a la derecha y encuentra un 3 m 
    °   *
1 2 3 2 4 3
*/



#include <iostream>
#include <vector>
using namespace std;

int MoveElements(vector<int> &arr , int x){
    int slow = 0;
    int fast = 0;

    while(fast < arr.size()){
        if(arr[fast] != x){
            arr[slow] = arr[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}

int main(){
    vector<int> v = {3, 1, 3, 2, 4, 3};
    int x = 3;
    int newLength = MoveElements(v, x);
    
    cout << "Nueva longitud: " << newLength << endl; // Debería imprimir: Nueva longitud: 3

    cout << "Vector resultante: ";
    for(int i = 0; i < newLength; i++){
        cout << v[i] << " "; // Debería imprimir: 1 2 4
    }
    cout << endl;

    return 0;
}