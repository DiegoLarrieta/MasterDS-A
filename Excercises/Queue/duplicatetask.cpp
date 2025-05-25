/*

🔹 3. 🏷 Identificador de tareas duplicadas
Enunciado:
Recibes tareas (nombres) en orden. Si una tarea ya fue recibida recientemente (últimos k tareas), se ignora. Si no, se procesa.

Input:

Tareas: A, B, C, A, D, B  
k = 3

Output:

✅ Procesa A  
✅ Procesa B  
✅ Procesa C  
❌ Ignora A (ya estuvo en últimas 3)  
✅ Procesa D  
❌ Ignora B

*/
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

void processTask(queue<string> &tasks, int k){
    // Crear un conjunto para almacenar las tareas recientes
    unordered_set<string> recentTask;

    // Recorrer las tareas
    while(!tasks.empty()){
        string task = tasks.front();
        tasks.pop();

        // Si la tarea ya está en el conjunto, la ignoramos
        // Si no, la procesamos y la agregamos al conjunto

        if(recentTask.find(task) != recentTask.end()){
            cout << "❌ Ignora " << task << " (ya estuvo en últimas " << k << ")" << endl;
        } else {
            // Procesar la tarea
            cout << "✅ Procesa " << task << endl;
            recentTask.insert(task);
        }

    }
        // Limitar el tamaño del conjunto a k
        if(recentTask.size() > k){
            recentTask.erase(recentTask.begin());
        }
}

int main() {
    queue<string> tasks;
    tasks.push("A");
    tasks.push("B");
    tasks.push("C");
    tasks.push("A");
    tasks.push("D");
    tasks.push("B");

    int k = 3;

    processTask(tasks, k);

    return 0;
}