/*
Ejercicio 5: Revertir las palabras de una oración (sin cambiar letras individuales)
🧠 Enunciado:
Dada una cadena con palabras separadas por espacios, revierte el orden de las palabras, pero mantén las letras de cada palabra en su orden.

Hazlo in-place si la entrada es un vector<char>, o devuelve un nuevo string.

string ReverseWords(const string& s);
Entrada: 
"hola mundo esto"

Salida:
"esto mundo hola"

Paso 1: Reversa la cadena completa
"hola mundo esto" → "otse odnum aloh"

Paso 2: Reversa cada palabra
*/

#include <iostream>
#include <vector>
using namespace std;

void ReverseWords(string &sentence){
    int low= 0;
    int high = sentence.size()-1;

    //Reversa de cadena completa
    while(low < high){
        swap(sentence[low], sentence[high]);
        low++;
        high--;
    }

    //Reversa de cada palabra
    low = 0;
    high = 0;
    // Recorre la cadena y encuentra los espacios
    // para identificar el inicio y fin de cada palabra y revertirla
    for(int i = 0; i < sentence.size(); i++){
        if(sentence[i] == ' '){
            high = i - 1;
            // Reversa la palabra
            while (low < high) {
                swap(sentence[low], sentence[high]);
                low++;
                high--;
            }
            low = i + 1;  // Empieza la siguiente palabra
        }
    }
    // Reversa la última palabra
    // (ya que no hay espacio al final)
    high = sentence.size() - 1;
    while (low < high) {
        swap(sentence[low], sentence[high]);
        low++;
        high--;
    }
}

int main(){
    string sentence = "hola mundo esto";
    ReverseWords(sentence);
    cout << "Cadena invertida: " << sentence << endl; // Debería imprimir: "esto mundo hola"
    return 0;
}