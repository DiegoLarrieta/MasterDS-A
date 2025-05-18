/*
🧠 Ejercicio: Validar paréntesis balanceados con múltiples tipos
🎯 Enunciado:
Dado un string que contiene solo los siguientes caracteres: '(', ')', '{', '}', '[', ']',
determina si el string es válido.

✅ Reglas:
Todo paréntesis abierto debe ser cerrado por el mismo tipo de paréntesis.

El orden de cierre debe ser el correcto y en anidación válida.


Input: "()"        → Output: true  
Input: "()[]{}"    → Output: true  
Input: "(]"        → Output: false  
Input: "([)]"      → Output: false  
Input: "{[]}"      → Output: true

*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s){

    // Definir la estructura 
    stack<char> pila;

    // Iterear sobre cada caracter

    for(int i = 0; i < s.length(); i++){
        char c =  s[i];

        // Si el parentesis es de apertura lo metemos al stack
        if( c == '(' || c == '[' || c == '{'){
            pila.push(c);

        }

        else if(c == ')' || c == ']' || c == '}'){
            // Si el stack esta vacio no hay con que cerrarlo
            if(pila.empty()){
                return false;
            }

            char top = pila.top();
            pila.pop();

            // ❌ Si no es el par correcto, inválido
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }

        }
    }
        // ✅ Al final, el stack debe estar vacío
        return pila.empty();
}

int main(){
    string test1 = "()[]{}";

    isValid(test1) ? cout << "✅ Válido\n" : cout << "❌ Inválido\n";
}