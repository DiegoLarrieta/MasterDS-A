/*
VENTANA DE TAMAÑO DINAMICO

🎯 Enunciado:
Dado un arreglo de números positivos y un valor target, encuentra la longitud mínima de la subarreglo 
continuo cuya suma sea mayor o igual a target. Si no hay tal subarreglo, devuelve 0.

arr = [2, 3, 1, 2, 4, 3], target = 7
→ Posibles subarreglos: [4, 3] → suma = 7 → longitud = 2 ✅
✅ Resultado: **2**

end = 0 → suma = 2
end = 1 → suma = 2 + 3 = 5
end = 2 → suma = 5 + 1 = 6
end = 3 → suma = 6 + 2 = 8 ✅ suma >= 7

    ➤ ventana = [0, 3] → tamaño = 4 → minLen = 4
    ➤ restamos array[0] = 2 → suma = 6
    ➤ start++

end = 4 → suma = 6 + 4 = 10 ✅ suma >= 7

    ➤ ventana = [1, 4] → tamaño = 4 → minLen sigue en 4
    ➤ restamos array[1] = 3 → suma = 7
    ➤ start++

    ➤ ventana = [2, 4] → tamaño = 3 → ✅ minLen = 3
    ➤ restamos array[2] = 1 → suma = 6
    ➤ start++

end = 5 → suma = 6 + 3 = 9 ✅ suma >= 7

    ➤ ventana = [3, 5] → tamaño = 3 → minLen sigue en 3
    ➤ restamos array[3] = 2 → suma = 7
    ➤ start++

    ➤ ventana = [4, 5] → tamaño = 2 → ✅ minLen = 2
    ➤ restamos array[4] = 4 → suma = 3
    ➤ start++

🔚 Terminamos. minLen final = 2
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayGreaterTarget(const vector<int> &array , int target) {
    int suma = 0;
    int start = 0;
    int minLen = INT_MAX;

    for(int end = 0; end < array.size(); end++){
        suma += array[end];

        while(suma >= target){
            // 3 - 0 + 1 = 4
            int windowSize = end - start + 1;
            if(minLen > windowSize){
                minLen = windowSize;
            }

            // Quitamos el primer elemento de la suma , ya que moveremos el puntero start
            suma = suma - array[start];
            // Contraemos desde la izquierda es como recorrer el puntero start a la derecha
            start++;
        }
    }
    return minLen;

}

int main(){
    vector<int> array = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = minSubArrayGreaterTarget(array, target);

    cout<<result<<endl;
}