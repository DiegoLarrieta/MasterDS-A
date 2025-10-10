//Leetcode 3 - Longest Substring Without Repeating Characters
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
// O(n) time complexity
// O(N) space complexity

int lenghtOfLongestSubstring(string s){

    // Paso 1 - Crear un set para almacenar los caracteres que hemos visto en la ventana actual
    unordered_set<char> charSet;

    // Paso 2 Inicializar el puntero de la izquierda y la derecha , que indicaran tu ventana
    int left = 0;
    //int right = 0; este lo declaras dentro del for

    // Paso 3 Inicializar la variable para almacenar la longuitud 
    int maxLength = 0;

    // Paso 4 - Iterar a traves de la cadena con el puntero derecho
    for(int right = 0; right < s.length(); right++){
        // 5. Si el caracter en la posicion actual de right ya esta en el set, significa que ya tenemos un duplicado
        // charset.end()
        while(charSet.find(s[right]) != charSet.end()){
            // Si tenemos un duplicado, removemos el caracter en la posicion left del set y movemos left a la derecha
            charSet.erase(s[left]);
            left++;
        }

        // 6. Agregamos el caracter en la posicion right al set
        charSet.insert(s[right]);

        // 7. Actualizamos la longuitud maxima
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}