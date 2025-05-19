/*
LeetCode 2390: Removing Stars from a String

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.

*/

#include <iostream>
#include <stack>

using namespace std;

string removeStars(string s){

    // Definir el stack

    stack<char>pila;

    // Iterar sobre la cadena

    for( int i = 0 ; i < s.length(); i++){
        char c = s[i];

        // Si es un asterisco , eliminamos el tope

        if ( c == '*'){
            if(!pila.empty()){
                pila.pop();
            }
        }
        else{
            pila.push(c); // Agregamos el caracter al stack
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
    string test = "leet**cod*e"; // Puedes probar con "azxxzy", "aabbcc", etc.
    cout << removeStars(test) << endl; 
    return 0;
}
