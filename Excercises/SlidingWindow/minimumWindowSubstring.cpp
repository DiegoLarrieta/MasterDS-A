// Leetcode 76 - Minimum Window Substring

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



string minWindow(string s, string t) {
    // edge case
    if (t.empty()) return "";

    // Nota: Como el problema acepta letras en mayusculas o minusculas es mejor utilizar un hash map

    // 1. Crear hash map para t y para la ventana actual en s
    unordered_map<char,int>freqT;
    unordered_map<char,int>freqSWindow;


    // 2. Crear una variable para calcular el size
    int windowSize = INT_MAX;

    // Crear variable para guardar el resultado en un string
    pair<int, int> res = {-1, -1};

    // Crear puntero left
    int left = 0;

    // 3. Llenar las frecuenbcias de t
    for(char c : t){
        freqT[c]++;
    }

    // 4. Crear variables para have y need , que debe ser declarada despues de llenar freqT
    int have = 0;
    int need = freqT.size();

    // 4. Comenzar la ventana
    for(int right = 0; right < s.length(); right++){
        // Agregar el caracter y frecuencia de right a nuestro hash de frecuencias de la ventana
        char c = s[right];
        freqSWindow[c]++;

        // Si el caracter en right esta en freqT es porque es un elemento que nos interesa
        // Y su frecuencia es menor o igual que la frecuencia de T aumentamos el valor de have
        if(freqT.count(c) && freqSWindow[c] == freqT[c]){
            have++;
        }

        // Mientras la ventana sea valida osea que have == need
        while(have == need){
            // Vamos a calcular el valor de esta ventana
            int curLen = right - left + 1;
            if (curLen < windowSize) {
                windowSize = curLen;
                res = {left, right}; 
            }

            // Despues tenemos que eliminar la frecuencia del elemento que nos estamos saltando
            char leftChar = s[left];
            freqSWindow[leftChar]--;

            // Si el caracter en left es de los que nos importan y su frecuencia es menor que su frecuencia en t
            // Significa que la ventana no es valida asi que decrementamos have
            if(freqT.count(leftChar) && freqSWindow[leftChar] < freqT[leftChar]){
                have--;
            }

            // Movemos left a la derecha para reducir la ventana
            left++;
        }
    }
    return windowSize == INT_MAX ? "" : s.substr(res.first, windowSize);
}