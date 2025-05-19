/*
LEETCODE 1544 Make the string Great
Given a string s of lower and upper case English letters.

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".


*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string makeGood(string s){

    // Definir el stack
    stack<char>pila;

    // Iterar sobre la cadena

    for(int i = 0; i < s.length(); i++){
        char c = s[i];

        // Para eliminar el caracter actual si es mayuscula , con el anterior
        if (!pila.empty() && abs(pila.top() - c) == 32){
            pila.pop();
        }

        // Si no es mayuscula , pues los agregamos normal
        else{
            pila.push(c);
        }
    }
    // Convertir el stack a string 
    string resultado = "";
    while(!pila.empty()){
        resultado = pila.top() + resultado;
        pila.pop();
    }

    return resultado;
}

int main(){
    string test = "leEeetcode"; // Puedes probar con "azxxzy", "aabbcc", etc.
    cout << makeGood(test) << endl; 
    return 0;
}

