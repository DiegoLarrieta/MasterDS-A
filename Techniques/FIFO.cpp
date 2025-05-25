/*
First In - First Out
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Función que simula la atención de una fila de personas
void atenderFila(queue<string> fila) {
    cout << "📋 Simulando atención FIFO:\n";
    
    while (!fila.empty()) {
        cout << "🎯 Atendiendo a: " << fila.front() << endl;
        fila.pop(); // Sale el primero
    }

    cout << "✅ Todos han sido atendidos.\n";
}

int main() {
    // Creamos la fila
    queue<string> filaClientes;

    // Agregamos personas
    filaClientes.push("Juan");
    filaClientes.push("Ana");
    filaClientes.push("Luis");
    filaClientes.push("Diego");

    // Llamamos la función
    atenderFila(filaClientes);

    return 0;
}
