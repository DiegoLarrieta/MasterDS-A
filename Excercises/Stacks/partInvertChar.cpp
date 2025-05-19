/*
LEETCODE 2000
🔹 6. Reversa parcial hasta un carácter
🎯 Dado un string y un carácter ch, revierte el segmento que empieza en índice 0 y termina en la primera aparición de ch (inclusive).

Si ch no existe, el string se devuelve igual.

Input:
word = "abcdefd", ch = "d"

Output:
"dcbaefd"
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reversePrefix(string word, char ch){
    //Utilzar un stack
    stack<char> pila;

    int pos = -1;

    // Iterar sobre cada caracter del string
    for(int i = 0; i < word.length(); i++){
        char c = word[i];
        pila.push(c); // Agregamos el caracter al stack

        // Si el caracter es igual a ch guardamos la posicion
        if(c  ==  ch){
            pos = i; // Guardamos la posicion
            break;

        }
    }
    // Si no se encontro el caracter ch,retornamos la palabra original 
    if(pos == -1){
        return word;
    }

    // Convertir el stack a string
    string resultado = "";
    while(!pila.empty()){
        // Agregamos el tope al resultado
        resultado += pila.top();

        // Eliminamos el tope
        pila.pop();
    }
    // Agregamos el resto de la cadena
    return resultado += word.substr(pos + 1);
    
}

int main(){
    string test = "abcdefg";
    char ch = 'd';

    cout << reversePrefix(test, ch) << endl;
}