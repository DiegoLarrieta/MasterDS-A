/*
Ejercicio 2: Palabra invertida
🧠 Enunciado:
Dada una palabra como vector de caracteres, invierte sus letras.


Input:  ['h', 'e', 'l', 'l', 'o']
Output: ['o', 'l', 'l', 'e', 'h']

*/

#include <iostream>
#include <vector>
using namespace std;

void ReverseWord(vector<char> &word){
    int low = 0;
    int high =  word.size()-1;

    while(low < high){
        swap(word[low], word[high]);
        low++;
        high--;
    }
}

int main(){
    vector<char> word = {'h', 'e', 'l', 'l', 'o'};

    ReverseWord(word);
    cout<<"Palabra invertida: ";
    for(int i = 0; i<word.size(); i++){
        cout<<word[i] << " ";
    }
    cout<<endl;
}