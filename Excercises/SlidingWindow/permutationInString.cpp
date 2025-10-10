// Leetcode 567 - Permutation in String
#include <iostream>
#include <vector>

using namespace std;
// o(n) time complexity
// o(1) space complexity
bool checkInclusion(string s1, string s2){

    // Edge case - si s1 es mas grande que s2, no puede haber ninguna permutacion
    if(s1.length() > s2.length()) return false;

    // Paso 1 - Crear un vector para hacer y almacenar el conteo de frecuencias , 
    vector<int> freqS1(26,0);
    vector<int> freqS2(26,0);

    // Paso 2 Comenzamos nuestra ventana , recordando que es de tamano s1
    for(int i = 0; i < s1.length(); i++){
        // Hacemos el conteo de frecuencias para s1
        freqS1[s1[i] - 'a']++;
        // Hacemos el conteo de frecuencias para la primera ventana de s2
        freqS2[s2[i] - 'a']++;
    }

    // Paso 3 Si las frecuencias son iguales, significa que la primera ventana es una permutacion
    if(freqS1 == freqS2) return true;

    // Paso 4 Si las frecuencias no son iguales, movemos la ventana a la derecha
    // I representa el nuevo caracter que entra en la ventana
    for(int i = s1.length() ; i < s2.length() ; i++){
        // Actualizamos el conteo de frecuencias con el elemento que entra en la ventana
        freqS2[s2[i] - 'a']++;

        // Actualizamos el conteo de frecuencias con el elemento que sale de la ventana
        freqS2[s2[i - s1.length()] - 'a']--;

        // Despues comparamos las frecuencias
        if(freqS1 == freqS2) return true;
    }

    // Si nunca fueron iguales retornamos false 
    return false;


}