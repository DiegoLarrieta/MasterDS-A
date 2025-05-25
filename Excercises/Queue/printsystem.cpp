/*
🔹 4. 📦 Simulación de sistema de impresión
Enunciado:
Dado un queue con documentos (número de páginas), simula la impresora imprimiendo uno por uno. Si un documento tiene más de 10 páginas, divídelo en partes de 10.

Input:

[5, 15, 3]

Output:

Imprime 5p  
Imprime 10p (de 15)  
Imprime 5p (restante)  
Imprime 3p

*/

#include <iostream>
#include <queue>

using namespace std;

void printSystem(queue<int> documents){

    while( !documents.empty()){

        int pages = documents.front();
        documents.pop();

        // Si el documento tiene mas de 10 paginas lo dividimos 
        while( pages > 10){
            cout << "Imprime 10p (de " << pages << ")" << endl;
            pages -= 10;
        }
        // Si el documento tiene menos de 10 paginas lo imprimimos
        if(pages > 0){
            cout << "Imprime " << pages << "p" << endl;
        }
    }
}

int main(){
    queue<int> documents;
    documents.push(5);
    documents.push(15);
    documents.push(3);

    printSystem(documents);

    return 0;
}