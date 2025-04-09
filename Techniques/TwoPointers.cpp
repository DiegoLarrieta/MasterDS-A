#include <iostream>
#include <vector>
using namespace std;


//  ← referencia → modifica el original directamente
void TwoPointers(const vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;

    // Este es el patrón general de dos punteros
    while (left < right) {
        // 🔍 Puedes hacer comparaciones entre arr[left] y arr[right]
        // o usar uno de ellos como condición, o incluso mover solo uno

        cout << "Comparando: " << arr[left] << " y " << arr[right] << endl;

        // Aquí decides cómo mover los punteros según el problema
        left++;
        right--;
    }
}

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    TwoPointers(v);
    return 0;
}

/*
Imagina que tienes un archivo físico (tu vector).

Caso 1 (sin &): haces una fotocopia y marcas la copia → el original no se entera.

Caso 2 (con &): marcas directamente el original.

Caso 3 (const &): solo puedes mirar el original, pero no tocarlo.


*/
