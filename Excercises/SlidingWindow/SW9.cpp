/*
Ejercicio: Longest Substring With Only Unique Vowels
🎯 Enunciado:
Dado un string s, encuentra la longitud de la subcadena más larga que contenga solo vocales únicas 
(a, e, i, o, u) y sin repetirse.

📌 Si aparece una consonante, se rompe la ventana.

Input: "aeiouxyz"
Output: 5  
Explicación: "aeiou" tiene todas las vocales, todas únicas → ✅

Input: "aaeeiioouu"
Output: 1  
Explicación: Solo puedes tomar una vocal antes de que se repita

Input: "abcdeiouxyz"
Output: 4
Faltó solo la "a" para que fuera "aeiou" completa

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool esVocal(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u'){
        return true;
    }
    else{
        return false;
    }
}
int longestSubstringWithUniqueVowels(string s){
    int start = 0;
    int longestLenght = 0;

    unordered_set<char> character;

    for(int end = 0; end < s.size(); end++){
        // Si no es una vocal
        if (!esVocal(s[end])) {
            character.clear();     // 🔁 Limpiamos el set de vocales
            start = end + 1;       // ⏩ Reiniciamos la ventana justo después
            continue;              // 🚫 Saltamos este carácter porque no es vocal
        }

        // si el carácter SÍ está repetido.
        while (character.count(s[end])) {
            character.erase(s[start]);
            start++;
        }

        character.insert(s[end]);
        int windowSize = end - start + 1;
       
       if(windowSize > longestLenght){
        longestLenght = windowSize;
       }

    }
    return longestLenght;
}


int main(){
    string s = "abcdeiouxyz";
    int result = longestSubstringWithUniqueVowels(s);

    cout<<result<<endl;
}
