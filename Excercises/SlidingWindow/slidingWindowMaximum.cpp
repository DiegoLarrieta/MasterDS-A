// Leetcode 239 - Sliding Window Maximum

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    // Edge case cuando el vector esta vacio
    if(nums.empty()) return {};

    // Paso 1 - Crear un deque para almacenar los indices de los elementos en la ventana actual
    deque<int> dq;

    // Paso 2 - Crear un vector para almacenar los resultados
    vector<int> result;

    // Paso 3 - Declarar puntero derecho
    int left= 0;

    // Paso 4 Comenzar la ventana 
   for(int right = 0; right < nums.size(); right){

        // 5. Mantener el deque en orden decreciente
        // Si el elemento de la derecha es mauor que el elemento en el back del deque, removemos el elemento del back
        while(!dq.empty() && nums[dq.back()] < nums[right]){
            dq.pop_back();
        }

        //6. Si el elemento de la derecha es menor, lo agreguamos al back 
        dq.push_back(right);

        // 7. Remover el elemento que esta fuera de la ventana
        if(left > dq.front()){
            // Si el indice en el front del deque es menor que left, significa que este elemento ya no esta en la ventana
            dq.pop_front();
        }

        // 8. Si hemos alcanzado el tamano de la ventana, agregamos el maximo al resultado
        if((right + 1) >= k){
            result.push_back(nums[dq.front()]);
            left++;
        }
        right++;
    }
    
}
