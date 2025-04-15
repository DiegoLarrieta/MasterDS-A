#include <iostream>
#include <vector>
using namespace std;

/*
1, 3, 5, 2, 8, 0, 1


🧠 DEBUG EXPLICATIVO - TÉCNICA SLIDING WINDOW

Este programa toma un arreglo y aplica la técnica de ventana deslizante ("Sliding Window")
para recorrer subarreglos de tamaño fijo (`tamVentana`) y calcular la suma en cada uno.

1️⃣ Primero, inicializamos la suma con los primeros `tamVentana` elementos.
    → Ejemplo si tamVentana = 3: sumamos arreglo[0] + arreglo[1] + arreglo[2]

2️⃣ Luego, comenzamos a mover la ventana un paso hacia la derecha en cada iteración:
    - Restamos el elemento que sale por la izquierda de la ventana (arreglo[indiceInicio])
    - Sumamos el nuevo elemento que entra por la derecha (arreglo[indiceFin])
    - Imprimimos la nueva ventana y su suma actual

🧪 Este proceso nos permite recorrer todas las ventanas de tamaño fijo en el arreglo,
    sin tener que recalcular la suma desde cero en cada paso.

🎯 Resultado: suma eficiente de ventanas con complejidad O(n)

Ejemplo con arreglo = [1, 3, 5, 2, 8, 0, 1] y tamVentana = 3:

Ventana 0: [1, 3, 5] → suma = 9  
Ventana 1: [3, 5, 2] → suma = 9 - 1 + 2 = 10  
Ventana 2: [5, 2, 8] → suma = 10 - 3 + 8 = 15  
...
Y así sucesivamente.

*/




#include <iostream>
#include <vector>
using namespace std;

void MostrarVentanasConSuma(const vector<int>& arreglo, int tamVentana) {
    int tamanoTotal = arreglo.size();

    // Validamos que la ventana quepa en el arreglo
    if (tamVentana > tamanoTotal) {
        cout << "⚠️ La ventana es más grande que el arreglo." << endl;
        return;
    }

    // ✅ Paso 1: Calcular la suma inicial de la primera ventana
    int sumaVentana = 0;
    cout << "📌 Inicializando ventana con los primeros " << tamVentana << " elementos: "<<endl;
    for (int i = 0; i < tamVentana; i++) {
        sumaVentana += arreglo[i];
        cout << arreglo[i] << " ";
    }
    cout << "→ Suma inicial = " << sumaVentana << endl;

    // ✅ Paso 2: Deslizar la ventana hacia la derecha
    for (int indiceFin = tamVentana; indiceFin < tamanoTotal; indiceFin++) {
        int indiceInicio = indiceFin - tamVentana;

        // Restamos el elemento que salió por la izquierda
        int elementoQueSale = arreglo[indiceInicio];

        // Sumamos el elemento que entra por la derecha
        int elementoQueEntra = arreglo[indiceFin];

        // Actualizamos la suma de la ventana
        sumaVentana = sumaVentana - elementoQueSale + elementoQueEntra;

        // Mostramos la nueva ventana y su suma
        cout << "📦 Ventana [" << indiceInicio + 1 << " - " << indiceFin << "]: ";
        for (int j = indiceInicio + 1; j <= indiceFin; j++) {
            cout << arreglo[j] << " ";
        }
        cout << "→ Suma actual = " << sumaVentana << endl;
    }
}

int main() {
    vector<int> numeros = {1, 3, 5, 2, 8, 0, 1};
    int tamVentana = 3;

    MostrarVentanasConSuma(numeros, tamVentana);
}
