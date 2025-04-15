/*
Ejercicio 4: Verifica si una palabra es palíndromo (usando reverse)
🧠 Enunciado:
Verifica si una palabra leída al derecho es igual que al revés.Si es un palindromo

Input: "racecar"
Output: true

Input: "hello"
Output: false
*/

#include <iostream>
#include <vector>
using namespace std;

bool IsPalindrome(string word){
    int low  = 0;
    int high = word.size()-1;

    while(low <= high){
        if(word[low] == word[high]){
            low++;
            high--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    cout << boolalpha;

    string word = "hello";
 

    bool result = IsPalindrome(word);
    cout<< result << endl;
}