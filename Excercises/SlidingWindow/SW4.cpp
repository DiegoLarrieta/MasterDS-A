/*
Ejercicio 4: Suma máxima de ventana que contenga un número impar
🎯 Enunciado:
Devuelve la suma más alta entre las ventanas de tamaño k que contengan al menos un número impar.

✔️ Aquí introduces una condición interna dentro de la ventana.

{1, 2, 3, 4, 5, 6, 7}, k = 3
Window 1: [1, 2, 3] → suma = 6 odd = 1 and 3 
Windor 2: [2, 3, 4] → suma = 9 odd = 3
Window 3: [3, 4, 5] → suma = 12 odd = 3 and 5
Window 4: [4, 5, 6] → suma = 15 odd = 5
Window 5: [5, 6, 7] → suma = 18 odd = 5 and 7
Output: 15

*/
#include <iostream>
#include <vector>
using namespace std;

int SumaMaximaVentanaImparElement(const vector<int> &arr, int k) {
    //Get the size of the array
    int n = arr.size();

    // Validate that the window size is not larger than the array
    if (k > n){
        return 0;
    }

    int sumaVentana = 0;
    int maxSuma = 0;
    int cantidadImpares = 0;

    // Inicializar la primera ventana
    for (int i = 0; i < k; i++) {
        sumaVentana += arr[i];
        if (arr[i] % 2 != 0){
            cantidadImpares++;// 1
        }
    }
    if (cantidadImpares > 0){
        maxSuma = sumaVentana;
    }
    // Deslizar la ventana
    for (int i = k; i < n; i++) {
        int valorQueSale = arr[i - k];
        int valorQueEntra = arr[i];

        sumaVentana = sumaVentana - valorQueSale + valorQueEntra;

        // Actualizar cantidad de impares
        if (valorQueSale % 2 != 0) cantidadImpares--;
        if (valorQueEntra % 2 != 0) cantidadImpares++;

        if (cantidadImpares > 0 && sumaVentana > maxSuma) {
            maxSuma = sumaVentana;
        }
    }

    return maxSuma;
}



int main(){
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};
    int windowSize = 3;

    int result = SumaMaximaVentanaImparElement(numbers, windowSize);

    cout << result << endl;
    return 0;
}