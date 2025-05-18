#include <iostream>
#include <stack>
using namespace std;

bool parentesisBalanceados(string s) {
    stack<char> pila;

    // for (int i = 0; i < s.lengt() ; i++)
    // char c = s[i];
    for (char i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(') {
            pila.push(c);  // 👉 Abrimos un paréntesis, lo guardamos
        } else if (c == ')') {
            if (pila.empty()){
                return false; // ❌ No hay con qué cerrarlo
            }
            pila.pop();  // ✅ Cerramos el paréntesis más reciente
        }
    }

    return pila.empty();  // ✅ Si está vacío, todo está balanceado
}

int main() {
    string test = "())";  // Puedes probar con "(()", "())", etc.
    cout << (parentesisBalanceados(test) ? "✅ Balanceado" : "❌ No balanceado") << endl;
}
