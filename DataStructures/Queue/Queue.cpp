#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Creamos una cola de enteros
    queue<int> fila;

    cout << "Inicialmente, la cola está vacía? " << (fila.empty() ? "Sí" : "No") << endl;

    // Enqueue: Insertamos elementos al final
    fila.push(10);
    fila.push(20);
    fila.push(30);

    cout << "\nSe agregaron 3 elementos: 10, 20, 30\n";
    cout << "Tamaño actual de la cola: " << fila.size() << endl;

    // Front: Vemos el primer elemento (no lo eliminamos)
    cout << "Elemento al frente de la cola: " << fila.front() << endl; // 10

    // Back: Último elemento de la cola
    cout << "Último elemento agregado (al final): " << fila.back() << endl;

    // Dequeue: Quitamos el primer elemento (FIFO)
    fila.pop();
    cout << "\nDespués de hacer un pop (eliminamos el 10):" << endl;
    cout << "Nuevo frente de la cola: " << fila.front() << endl;
    cout << "Tamaño actual de la cola: " << fila.size() << endl;

    // Vaciamos la cola completamente
    cout << "\nVaciando la cola..." << endl;
    while (!fila.empty()) {
        cout << "Eliminando: " << fila.front() << endl;
        fila.pop();
    }

    cout << "La cola está vacía? " << (fila.empty() ? "Sí" : "No") << endl;

    return 0;
}
