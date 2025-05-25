/*
🔹 3. Number of Recent Calls (Recent Counter)
📘 LeetCode 933
Cada vez que llega un número (llamada), cuéntalas si ocurrieron en los últimos 3000ms. t - 300

Ideal para queue: mantienes los timestamps y haces pop cuando se pasan de rango

RecentCounter rc;

rc.ping(1);     // [1]                → 1 llamada válida
rc.ping(100);   // [1, 100]           → 2 llamadas válidas
rc.ping(3001);  // [1, 100, 3001]     → 3 llamadas válidas (aún dentro de 3000ms)
rc.ping(3002);  // [100, 3001, 3002]  → 3 llamadas válidas (1 ya salió)

*/

#include <iostream>

#include <queue>

using namespace std;

class RecentCounter{
    public:
        queue<int> q;

        RecentCounter(){
            //Constructor vacio
        }

        // para agregar un numero al timestamp
        int ping(int t) {
            q.push(t);

            while(!q.empty() && q.front() < t - 3000){
                // para eliminar los timestamps que ya no son validos
                q.pop();
            }
            //retornar el tamaño de la cola
            return q.size();
        }
};