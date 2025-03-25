/*
LeetCode Problem: Search Insert Position (Easy)
Problem Description:

Given a sorted array of distinct integers and a target value, 
return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

*/

#include <iostream>
using namespace std;
#include <vector>
#include <sstream>


int binarySearch(int arr[], int size, int target){
    // Posicion de la izquierda
    int left = 0;

    // Posicion de la derecha
    int right = size - 1; // size - 1 porque los indices empiezan en 0

    //Mientras la posicion de la izquierda sea menor o igual a la derecha
    //
    while(left <= right){
        // Posicion del medio
        int mid = left + (right - left) / 2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            left = mid + 1; //Buscar en la mitad derecha
        }else{
            right = mid - 1; //Buscar en la mitad izquierda
        }
    }
    return left; // Regresar la posicion donde deberia estar el elemento
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int target;

    cout << "Enter the elements of the array (space-separated): ";
    string input;
    getline(cin, input); // Leer toda la línea de entrada
    stringstream ss(input); // Usar stringstream para procesar los números
    int num;
    while (ss >> num) {
        arr.push_back(num); // Agregar cada número al vector
    }

    cout << "Enter the target value: ";
    cin >> target;

    int size = arr.size();

    int result = binarySearch(arr.data(), size, target);

    cout<<result<<endl;

    // Aquí puedes llamar a tu función de búsqueda binaria o cualquier otra lógica
    return 0;
}


