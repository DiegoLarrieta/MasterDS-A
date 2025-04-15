/*
Ejercicio: Longest Substring Without Repeating Characters
🎯 Enunciado clásico de entrevistas:
Dado un string s, encuentra la longitud de la subcadena más larga sin caracteres repetidos.
Input:  "abcabcbb"
Output: 3  // Substring: "abc"

Input:  "bbbbb"
Output: 1  // Substring: "b"

Input:  "pwwkew"
Output: 3  // Substring: "wke"

Input: "dvdf"
Output: 3  // Substring: "vdf"

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Voy a utilizar unordered_set que es O(1)

int longestSubstringWithoutRepeating(string s){
    // Calculamos el tamaño del string
    int n = s.size();

    // Puntero que apunta al inicio
    int start = 0;

    // Variable para calcular el maxlenght
    int maxLenght = 0;

    unordered_set<char> caracter;


    for(int end = 0; end < n ; end++){
        // Mientras haya duplicados, eliminamos desde la izquierda
        // .count verifica si el elemento ya esta en el set, retorna 1 si ya esta y 0 si no 
        // entonces aqui es para ver si el caracter ya esta en nuestro set
        while(caracter.count(s[end])){
            caracter.erase(s[start]);
            start++;
        }
        // Ahora que s[end] ya no es duplicado, lo insertamos
        caracter.insert(s[end]);

        // Calculamos la longitud de la ventana actual válida
        int windowSize = end - start + 1;
        if(windowSize > maxLenght){
            maxLenght = windowSize;
        }


    }

    return maxLenght;
}

int main(){
    string s = "abcabcbb";
    int result = longestSubstringWithoutRepeating(s);

    cout<<result<<endl;
}