/*
🔹 Ejercicio: Simular fila en la taquilla 🎟️
🎯 Enunciado:
Imagina que estás programando la fila de una taquilla de cine.
A cada persona que llega le asignas un número (1, 2, 3, ...).
Simula el proceso de atención y muestra el orden en el que son atendidos.

Input
Llega el cliente 1  
Llega el cliente 2  
Llega el cliente 3  

Output
Atendiendo a cliente 1  
Atendiendo a cliente 2  
Atendiendo a cliente 3  

*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

void atenderFila(queue<int> fila){
    while(!fila.empty()){
        cout<<"Atentiendo al cliente "<<fila.front()<<endl;

        // Lo eliminamos
        fila.pop();
    }
}

int main(){
    queue<int> filaClientes;

    // Agregamos personas
    filaClientes.push(1);
    filaClientes.push(2);
    filaClientes.push(3);

    // Llamamos la función
    atenderFila(filaClientes);

    return 0;
}