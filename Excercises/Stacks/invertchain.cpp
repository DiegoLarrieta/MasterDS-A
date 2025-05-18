/*
✅ 2. Inversión de una cadena
Input: "hello"
Output: "olleh"

🎯 Push de cada letra, luego pop para invertir

*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;


string invertChain(const string &s){
    stack  <char> pila;

    // Iteramos sobre cada caracter de la cadena
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        pila.push(c); // Agregamos el caracter al stack
    }

    // Convertimos el stack a string
    string resultado = "";
    while(!pila.empty()){
        resultado += pila.top(); // Agregamos el tope al resultado
        pila.pop(); // Eliminamos el tope
    }
    return resultado; // Devolvemos el resultado

}

int main(){
    string test = "hello";
    cout << invertChain(test) << endl; 
    return 0;
}