/*
🔹 1. Postfix Evaluation (Expresiones en Notación Postfija)
🎯 Dada una expresión en notación postfija (Reverse Polish Notation), evalúa su resultado.

📥 Input:
cpp
Copiar
Editar
tokens = ["2", "1", "+", "3", "*"]
📤 Output:
cpp
Copiar
Editar
9  // Porque (2 + 1) * 3 = 9
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>



using namespace std;

int evalRPN(vector<string>& tokens){

    // Defiinit stack 
    stack<int> bote;

    // Iterar sobre la cadena

    for(int i = 0; i < tokens.size(); i++){
        string hilde =  tokens[i];

        // Si es un numero lo agregamos 

        if(hilde != "+" && hilde != "-" && hilde != "*" && hilde != "/"){

            // pasarlo a entero
            bote.push(stoi(hilde));
        }

        // Si es un operador lo evaluo

        else{
            int b = bote.top(); // Sacamos el de hasta arriba
            bote.pop();//Lo eliminamos

            int a = bote.top();
            bote.pop();

            int resultado = 0;

            // operaciones logicas 

            if(hilde == "+"){
                resultado = a + b;
            }
            else if(hilde == "-"){
                resultado = a - b;
            }
            else if(hilde == "*"){
                resultado = a * b;
            }
            else if(hilde == "/"){
                resultado = a / b;
            }

            // agregamos el resultado al bote
            bote.push(resultado);
        }   
    }
    // retonar resultado
    return bote.top();
}

