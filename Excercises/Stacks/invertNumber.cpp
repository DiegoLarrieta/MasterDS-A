/*

🔹 1. Inversión de número
🎯 Invierte un número usando stack.

Input: 12345
Output: 54321

// LIFO 
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int invertNumber(const int &n){

    // DEFINIR STACK
    stack<int> pila;

    // Convertir el número a string

    string numero = to_string(n);

    // Iterar sobre cada dígito y agregarlo al stack

    for(int i = 0; i < numero.length(); i++){
        char c = numero[i];
        pila.push(c);
    }

    string resultado = "";

    while(!pila.empty()){
        // Agregamos el primer elemento de la pila 
        resultado += pila.top();

        // Eliminamos el primer elemento de la pila
        pila.pop();
    }

    return stoi(resultado);
}


int main(){
    int test = 12345;

    cout<< invertNumber(test) << endl;
}
