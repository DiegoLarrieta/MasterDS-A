/*
2696. Minimum String Length After Removing Substrings

You are given a string s consisting only of uppercase English letters.
You can apply some operations to this string where, in one operation, 
you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Example 1:

Input: s = "ABFCACDB"
Output: 2
Explanation: We can do the following operations:
- Remove the substring "ABFCACDB", so s = "FCACDB".
- Remove the substring "FCACDB", so s = "FCAB".
- Remove the substring "FCAB", so s = "FC".
So the resulting length of the string is 2.
It can be shown that it is the minimum length that we can obtain.

*/
#include <iostream>
#include <stack>

using namespace std;

int minLength(string s){

    // Definir stack
    stack<char>pila;

    // Iterar sobre la cadena

    for(int i = 0 ; i < s.length();i++){
        char c = s[i];

        // AB Y CD , si los encuentras los debemos de eliminar
        if(!pila.empty() && ((pila.top() == 'A' && c == 'B') || (pila.top() == 'C' && c == 'D'))){
            pila.pop(); // Eliminamos el tope
        }
        else{
            pila.push(c); // Agregamos el caracter al stack
        }
    }
    // Retornar el tamaño del stack
    return pila.size();
}

int main(){
    string test = "ABFCACDB"; // Puedes probar con "azxxzy", "aabbcc", etc.
    cout << minLength(test) << endl; 
    return 0;
}