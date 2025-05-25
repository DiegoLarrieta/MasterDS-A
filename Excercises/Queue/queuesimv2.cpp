/*
🔹 1. 🏫 Simulador de atención en ventanilla
Enunciado:
Dado un vector de clientes con el tiempo que tardan en ser atendidos, simula el orden en que salen de la fila y 
calcula el tiempo total.

Input:
{4, 2, 5, 1}  // Tiempo por cliente

Output:
Cliente 1 atendido por 4s  
Cliente 2 atendido por 2s  
...  
⏱ Total: 12s
*/


#include <iostream>
#include <queue>

using namespace std;

void ventanilla(queue<int> clientes){
    int tiempoTotal = 0;
    int clienteActual = 1;

    while (!clientes.empty()) {
        int tiempoAtencion = clientes.front();
        clientes.pop();
        tiempoTotal += tiempoAtencion;
        cout << "Cliente " << clienteActual << " atendido por " << tiempoAtencion << "s" << endl;
        clienteActual++;
    }

    cout << "⏱ Total: " << tiempoTotal << "s" << endl;

}

int main(){
    queue<int> clientes;
    clientes.push(4);
    clientes.push(2);
    clientes.push(5);
    clientes.push(1);   
    ventanilla(clientes);
    return 0;
}