/*

🔹 5. 🚦Simulación de semáforo
Enunciado:
Simula el paso de autos por un semáforo que deja pasar solo 3 autos cada 10 segundos. Los autos llegan en cierto orden.

Input:

Autos: A, B, C, D, E, F  
Regla: 3 autos por tanda



Output:

Turno 1: A B C  
Turno 2: D E F

*/

#include <iostream>
#include <queue>

using namespace std;

void semaforo(queue<string> autos, int maxAutosPerTurn){

    int turno = 1;
    while(!autos.empty()){
        cout << "Turno: " << turno << ": ";

        for(int i = 0; i < maxAutosPerTurn; i++){
            cout<< autos.front() << " ";
            autos.pop();
        }
        turno ++;
        cout << endl;
    }
}

int main() {
    queue<string> autos;
    autos.push("A");
    autos.push("B");
    autos.push("C");
    autos.push("D");
    autos.push("E");
    autos.push("F");

    int maxAutosPerTurn = 3;

    semaforo(autos, maxAutosPerTurn);

    return 0;
}