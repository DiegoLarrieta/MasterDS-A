// Leetcode 1189

/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.\

Example 1:
Input: text = "nlaebolko"
Output: 1

Example 2:
Input: text = "loonbalxballpoon"
Output: 2

Example 3:
Input: text = "leetcode"
Output: 0

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
// O(n) where n is the length of the input string
int maxNumberOfBallons(string text){

    // creamos el hashmap, para guardar el caracter y su frecuencia
    unordered_map<char,int> ballonMap;

   // Creamos un string ballon para verificar si el caracter del text pertenece a la palabra ballon
    string ballon = "balloon";

    // Recorremos el texto y contamos la frecuencia de cada caracter y lo sumamos
    for(char c : text){
        // Si el caracter es parte de la palabra ballon, lo agregamos al mapa
        if(ballon.find(c) != string::npos){//string::npos significa que el caracter no fue encontrado
            ballonMap[c]++;
        }
    }
    // Ahora revisamos si tenemos todas las letras necesarias para formar la palabra ballon
    if(ballonMap.find('b') == ballonMap.end() ||
        ballonMap.find('a') == ballonMap.end() ||
        ballonMap.find('l') == ballonMap.end() ||
        ballonMap.find('o') == ballonMap.end() ||
        ballonMap.find('n') == ballonMap.end()){
            return 0; // Si no encontramos alguna letra de ballon, retornamos 0
        } else{
            //Si tenemos todas las letras, retornamos el minimo entre las frecuencias de las letras
            return min({ballonMap['b'], ballonMap['a'], ballonMap['l']/2, ballonMap['o']/2, ballonMap['n']});
        }       
}