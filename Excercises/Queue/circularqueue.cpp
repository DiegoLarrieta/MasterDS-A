/*
🔹 2. 🔁 Cola circular con eliminación
Enunciado:
Dado n personas numeradas del 1 al n, elimina a cada k persona hasta que quede una sola. Muestra el orden en que salen.

Este es una versión simplificada del problema de Josephus.

Input:
n = 5
k = 3

1 2 3 4 5 Eliminado 3 y de ahi recorres otras 3 posiciones y eliminas 1



Output:
Eliminado: 3  
Eliminado: 1  
Eliminado: 5  
Eliminado: 2  
Ganador: 4
*/


#include <iostream>
#include <queue>
using namespace std;

int circularQueue(int n , int k){

    // Declarar la queue 
    queue<int> q;

    // Incializar la queue 
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    while(!q.empty()){
        // Recorrer los k - 1 elementos , recuerda que es porque 0 indexded 
        for(int i = 0; i < k - 1; i++){
            // Sacar el primer elemento y volver a meterlo al final
            int x = q.front();
            q.pop();
            q.push(x);
        }
        // Sacar el elemento que se elimina
        cout << "Eliminado: " << q.front() << endl;
        q.pop();
    }
    // El ganador es el que queda al final
    cout << "Ganador: " << q.front() << endl;
    return q.front();
}

int main() {
    int n = 5; // Número de personas
    int k = 3; // Cada k-ésima persona es eliminada

    circularQueue(n, k);

    return 0;
}