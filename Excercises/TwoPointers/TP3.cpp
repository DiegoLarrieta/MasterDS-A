/*
Ejercicio 3: Eliminar duplicados de un vector ordenado
🎯 Enunciado:
Dado un vector de enteros ordenado de forma creciente, elimina todos los elementos duplicados in-place, de forma que cada elemento aparezca solo una vez.
Devuelve la nueva longitud del vector sin duplicados.

Entrada:  [1, 1, 2, 2, 3, 4, 4]
Resultado esperado: [1, 2, 3, 4, _, _, _] → longitud: 4

primera iteracion 
° *
1 1 2 2 3 4 4  = son iguales entonces lo movemos a la derecha 

°   *
1 1 2 2 3 4 4  = Son diferentes entonces movemos el puntero 1 a la derecha

  ° *  
1 1 2 2 3 4 4 = Los swapwamos y movemos una posicion a la derecha el puntero 2

  °   *
1 2 1 2 3 4 4  =  Son iguales muevo el puntero 2 a la derecha 

  °     *
1 2 1 2 3 4 4 = Son diferentes entonces movemos el puntero 1 a la derecha

    °   *
1 2 1 2 3 4 4 = Los swapwamos y movemos una posicion a la derecha el puntero 2

    °     *
1 2 3 2 1 4 4  = Son diferentes movemos el punter 1 a la derecha

      °   *
1 2 3 2 1 4 4 = Los swapwamos y movemos una posicion a la derecha el puntero 2

      °     *
1 2 3 4 1 2 4  = Se termina el while retorna la posicion del puntero 1 = 3 mas 1 para la longitud del vector = 4
*/

#include <iostream>
#include <vector>
using namespace std;

int RemoveDuplicates(vector<int> &arr){
    int pointerpos = 0;
    int pointermovespos = 1;

    while(pointermovespos < arr.size()){
        // Si el elemento en pointermovespos es diferente al elemento en pointerpos
        if(arr[pointerpos] == arr[pointermovespos]){
            pointermovespos++;
        }
        else{

            // Si son diferentes, movemos el puntero de posición a la derecha
            pointerpos++;

            // Y asignamos el valor de pointermovespos a pointerpos
            arr[pointerpos] = arr[pointermovespos];
            pointermovespos++;
        }
    }
    // Retornamos la nueva longitud del vector sin duplicados
    return pointerpos + 1;
}
int main(){
    vector<int> v = {1, 1, 2, 2, 3, 4, 4};
    int newLength = RemoveDuplicates(v);

    cout << "Nueva longitud: " << newLength << endl; // Debería imprimir: Nueva longitud: 4
    cout << "Vector sin duplicados: ";
    for(int i = 0; i < newLength; i++){
        cout << v[i] << " ";
    }
    cout << endl; // Debería imprimir: Vector sin duplicados: 1 2 3 4
}