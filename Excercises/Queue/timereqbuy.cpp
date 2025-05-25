/*
2073 Time Needed to Buy Tickets

Example 1:

Input: tickets = [2,3,2], k = 2

Output: 6

Explanation:

2 3 2  k = 2  -> Se resta 1 al primer elemnto y se resta k 

3 2 1  k = 1  Segundo 1 
2 1 2  k = 0 Segundo 2

-- Cuando k es 0 significa que nuestra persona esta al inicio por lo que tenemos que actualizar otra vez k para que sea size - 1; 
en un 0 indexded array para llevar el control de la persona 

1 2 1  k = 2 ( size - 1) Segundo 3
2 1    k = 1  Segundo 4
1 1    k = 0 Segundo 5

Aqui la persona que estamos observando es la que tiene 1 ticket y le queda 1 ticket por lo que se acaba el tiempo
1   Segundo 6



Input: tickets = [5,1,1,1], k = 0

Output: 8
k = posicion del que vamos a observar cuando acabe de comprar los tickets que necesita
5 1 1 1   -> 1 sec
1 1 1 4   -> 2 sec
1 1 4     -> 3 sec
1 4       -> 4 sec
4         -> 5 sec
3         -> 6 sec
2         -> 7 sec
1         -> 8 sec
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    // crear una queue

    queue<int> q;


    // llenar la queue con los tickets
    for (int i = 0; i < tickets.size(); i++) {
        q.push(tickets[i]);
    }
    // inicializar el tiempo
    int time = 0;
    
    // mientras la queue no esté vacía
    while (!q.empty()) {
        // sacar el primer elemento de la queue
        int front = q.front();
        q.pop();
        
        // si el primer elemento es el que estamos observando
        if (k == 0) {
            // si solo le queda un ticket, se acaba el tiempo
            if (front == 1) {
                time++;
                break;
            }
            // si le queda más de un ticket, se le resta uno y se vuelve a meter en la queue
            else {
                front--;
                q.push(front);
            }
        } else {
            // si no es el que estamos observando, se le resta uno y se vuelve a meter en la queue
            if (front > 0) {
                front--;
                q.push(front);
            }
        }
        
        // aumentar el tiempo
        time++;
        
        // si k es 0, significa que hemos llegado al final de la queue
        if (k == 0) {
            k = q.size() - 1; // actualizar k para que apunte al siguiente elemento
        } else {
            k--;
        }
    }
    return time;

}

int main() {
    vector<int> tickets = {5, 1, 1, 1};
    int k = 0;

    int result = timeRequiredToBuy(tickets, k);
    cout << "Tiempo requerido: " << result << " segundos" << endl; // Debería imprimir: 8

    return 0;
}