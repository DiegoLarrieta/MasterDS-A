#include <iostream>
#include <stack>
using namespace std;

int main() {
    // 🧱 Creamos una pila de enteros
    stack<int> pila;

    // ✅ Agregamos elementos con push()
    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout << "➡️ Elementos agregados: 10, 20, 30 (30 está en la cima)\n";

    // ✅ Mostramos el elemento en la cima
    cout << "🔍 Elemento en el tope: " << pila.top() << endl;

    // ✅ Quitamos el último elemento con pop()
    pila.pop();  // Elimina el 30
    cout << "🗑️ Hacemos pop()\n";
    cout << "🔍 Nuevo tope: " << pila.top() << endl;

    // ✅ Verificamos si está vacío
    if (pila.empty()) {
        cout << "📦 La pila está vacía.\n";
    } else {
        cout << "📦 La pila NO está vacía.\n";
    }

    // ✅ Agregamos más elementos
    pila.push(40);
    pila.push(50);
    cout << " Se agregaron 40 y 50 a la pila.\n";

    // 🔍 Simulamos un search manual (recorremos el stack)
    int objetivo = 20;
    bool encontrado = false;

    // ⚠️ Como no se puede recorrer directamente el stack, lo copiamos
    stack<int> copia = pila;

    while (!copia.empty()) {
        if (copia.top() == objetivo) {
            encontrado = true;
            break;
        }
        copia.pop();  // Quitamos el elemento para seguir buscando
    }

    if (encontrado) {
        cout << "✅ El número " << objetivo << " está en la pila.\n";
    } else {
        cout << "❌ El número " << objetivo << " NO está en la pila.\n";
    }

    return 0;
}
