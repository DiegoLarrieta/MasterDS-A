/*
Dado un string que contiene únicamente los caracteres '(', ')', '{', '}', '[', y ']', verifica si la entrada es válida.
Una entrada es válida si:

Los paréntesis se cierran en el orden correcto.

Cada paréntesis de apertura tiene su par de cierre correspondiente.

Input: "()"
Output: true

Input: "({[]})"
Output: true

Input: "([)]"
Output: false  // el orden está mal

Input: "{[}"
Output: false  // falta cierre


COMPLEJIDAD O(N)

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Itreramos sobre todo el string
bool isBalanced(const string &s){
    stack<char> pila;

    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        // Si es un parentesis de apertura lo metemos al stack
        if(c == '(' || c == '[' || c == '{'){
            pila.push(c);
        }

        // Si no es uno de cierre verifiacamos que coincida con uno que abre 
        else if(c  == ')' || c == ']' || c == '}'){
            if(pila.empty()){
                return false; // No hay con que cerrarlo
            }

            char top = pila.top();
            pila.pop();

            if((c == ')' && top != '(') ||
               (c == ']' && top != '[') ||
               (c == '}' && top != '{')){
                return false; // No coincide
            }
        }
    }
    return pila.empty();
}
// Testeamos la funcion
int main(){
    vector<string> testCases = {"()[]{}"};
    for(const string &test : testCases){
        cout << "Test: " << test << " => " << (isBalanced(test) ? "Balanced" : "Not Balanced") << endl;
    }
}
