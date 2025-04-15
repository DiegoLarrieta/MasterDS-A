/*
🟢 Mayor suma en una ventana de tamaño 3 es: 15
Para el vector {1, 3, 5, 2, 8, 0, 1}
La mejor ventana es [5, 2, 8] → suma = 15
*/

#include <iostream>
#include <vector>
using namespace std;

int MayorSumaVentana(const vector<int>& arreglo, int tamVentana) {
    int n = arreglo.size();

    // 🛑 Validamos que el arreglo sea suficientemente largo
    if (tamVentana > n) {
        cout << "⚠️ La ventana es más grande que el arreglo." << endl;
        return -1;
    }

    // ✅ Paso 1: Calcular la suma de la primera ventana
    int sumaActual = 0;
    for (int i = 0; i < tamVentana; i++) {
        sumaActual += arreglo[i];
    }

    // Inicializamos la mayor suma con la primera suma
    int mayorSuma = sumaActual;

    // ✅ Paso 2: Deslizar la ventana por el arreglo (desde el índice tamVentana hasta el final)
    for (int i = tamVentana; i < n; i++) {
        // ITERACION 1: i = 3 
        // ITERACION 2: i = 4
        // ITERACION 3: i = 5
        // ITERACION 4: i = 6
        // Restamos el valor que sale de la ventana
        int valorQueSale = arreglo[i - tamVentana];// 0 1 2 3  

        // Sumamos el nuevo valor que entra a la ventana
        int valorQueEntra = arreglo[i]; // 3 4 5 6 

        // Actualizamos la suma de la ventana de forma eficiente
        sumaActual = sumaActual - valorQueSale + valorQueEntra;

        // Verificamos si esta nueva suma es la más grande hasta ahora
        if (sumaActual > mayorSuma) {
            mayorSuma = sumaActual;
        }
    }

    // ✅ Retornamos la mayor suma encontrada en cualquier ventana
    return mayorSuma;
}

int main() {
    vector<int> numeros = {1, 3, 5, 2, 8, 0, 1};
    int tamVentana = 3;

    int resultado = MayorSumaVentana(numeros, tamVentana);

    cout << "🟢 Mayor suma en una ventana de tamaño " << tamVentana << " es: " << resultado << endl;
}
