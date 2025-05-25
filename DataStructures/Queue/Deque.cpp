/*
| Operación    | Lado                    |
| ------------ | ----------------------- |
| `push_back`  | Insertar al **final**   |
| `push_front` | Insertar al **inicio**  |
| `pop_back`   | Eliminar del **final**  |
| `pop_front`  | Eliminar del **inicio** |

*/

#include <iostream>
#include <deque>
using namespace std;

void demoDeque() {
    deque<int> d;

    // Insertamos al final
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    cout << "Después de push_back: ";
    for (int x : d) cout << x << " ";  // 10 20 30
    cout << endl;

    // Insertamos al inicio
    d.push_front(5);
    d.push_front(1);
    cout << "Después de push_front: ";
    for (int x : d) cout << x << " ";  // 1 5 10 20 30
    cout << endl;

    // Eliminamos del inicio
    d.pop_front();  // Quita el 1
    cout << "Después de pop_front: ";
    for (int x : d) cout << x << " ";  // 5 10 20 30
    cout << endl;

    // Eliminamos del final
    d.pop_back();  // Quita el 30
    cout << "Después de pop_back: ";
    for (int x : d) cout << x << " ";  // 5 10 20
    cout << endl;

    // Mostrar el frente y el final
    cout << "Frente: " << d.front() << ", Final: " << d.back() << endl;
}

int main() {
    demoDeque();
    return 0;
}
