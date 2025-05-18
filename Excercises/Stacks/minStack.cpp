/*
✅ 4. Min Stack (LeetCode #155)
Implementa un stack que pueda devolver el mínimo elemento en O(1)

Implementa una clase MinStack con las siguientes operaciones:

void push(int val)

void pop()

int top()

int getMin() → debe devolver el mínimo elemento actual del stack en O(1)
Pero el objetivo aquí es que getMin() funcione en O(1) tiempo constante.

*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    private:
        stack<int> pilaPrincipal;  // Guarda todos los valores
        stack<int> pilaMinimos;    // Guarda los mínimos históricos
    
    public:
        MinStack() {
            // Constructor vacío
        }
    
        void push(int val) {
            // Siempre insertamos en la pila principal
            pilaPrincipal.push(val);
    
            // Solo insertamos en pilaMinimos si es el nuevo mínimo
            if (pilaMinimos.empty() || val <= pilaMinimos.top()) {
                pilaMinimos.push(val);
            }
        }
    
        void pop() {
            // Si el que vamos a quitar es también el mínimo actual
            if (!pilaPrincipal.empty() && pilaPrincipal.top() == pilaMinimos.top()) {
                pilaMinimos.pop();
            }
    
            // Quitamos el tope de la pila principal
            pilaPrincipal.pop();
        }
    
        int top() {
            return pilaPrincipal.top();
        }
    
        int getMin() {
            return pilaMinimos.top();
        }
};

int main(){
    MinStack minStack;
    minStack.push(3);
    minStack.push(5);
    cout << "Mínimo actual: " << minStack.getMin() << endl; // 3
    minStack.push(2);
    minStack.push(1);
    cout << "Mínimo actual: " << minStack.getMin() << endl; // 1
    minStack.pop();
    cout << "Mínimo actual: " << minStack.getMin() << endl; // 2
    return 0;
}

