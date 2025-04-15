#include <iostream>
#include <vector>
using namespace std;

int SumaTotal(const vector<int>& arr) {
    int suma = 0;  // ✅ Inicializamos la suma total en cero

    // 🔁 Recorremos cada elemento del vector
    for (int i = 0; i < arr.size(); i++) {
        suma += arr[i];  // ➕ Sumamos el valor actual al acumulador
    }

    return suma;  // 🎯 Devolvemos el resultado final de la suma
}
int main() {
    vector<int> numeros = {3, 5, 2, 8};  // 🎯 Vector de ejemplo

    int total = SumaTotal(numeros);  // ⚙️ Llamamos a la función

    cout << "La suma total es: " << total << endl;  // 🖨️ Resultado: 18
}
