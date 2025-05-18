/*
✅ 1. Eliminar duplicados adyacentes
Input: "abbaca"
Output: "ca"

🔁 Vas empujando letras en el stack
🧠 Si el tope del stack es igual a la letra actual → lo eliminas
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;


string deleteduplicates(const string &s){
    stack<char>pila;

    // Iteramos sobre cada caracter de la cadena
    for(int i = 0; i < s.length(); i++){
        char c = s[i];

        // Tenemos que agregar el caracter al stack , si el caracter  no es igual al tope se agrega 
        // y si si es igual se eliminan ambos

        if(pila.empty() || pila.top() != c){
            pila.push(c); // Agregamos el caracter al stack
        }

        // Si el tope es igual al caracter actual, lo eliminamos
        else{
            pila.pop(); // Eliminamos el tope
        }
    }

    // Convertimos el stack a string
    string resultado = "";
    while(!pila.empty()){
        resultado = pila.top() + resultado; // Agregamos el tope al resultado
        pila.pop(); // Eliminamos el tope
    }
    return resultado; // Devolvemos el resultado
}

int main(){
    string test = "aaa"; // Puedes probar con "azxxzy", "aabbcc", etc.
    cout << deleteduplicates(test) << endl; 
    return 0;
}