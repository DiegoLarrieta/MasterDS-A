/*
Linear Search code 

LeetCode Problem: Check If N and Its Double Exist

Problem Description:

Given an array arr of integers, check if there exist two indices i and j such that:

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

Input: arr = [10, 2, 5, 3]
Output: true
Explanation: For i = 2 and j = 1, arr[i] = 5 is double of arr[j] = 2.

Input: arr = [7, 1, 14, 11]
Output: true
Explanation: For i = 2 and j = 0, arr[i] = 14 is double of arr[j] = 7.

Input: arr = [3, 1, 7, 11]
Output: false
Explanation: There is no pair of indices that satisfies the conditions.

*/

#include <iostream>
#include <vector>
using namespace std;
#include <sstream>

bool checkIfExist(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == 2 * arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    vector<int> arr;
    string input;

    // Leer los números del usuario en una sola línea
    cout << "Enter the elements of the array (space-separated): ";
    getline(cin, input); // Leer toda la línea de entrada
    stringstream ss(input); // Usar stringstream para procesar los números
    int num;
    while (ss >> num) {
        arr.push_back(num); // Agregar cada número al vector
    }

    // Llamar a la función checkIfExist
    bool result = checkIfExist(arr.data(), arr.size());

    cout<<result<<endl;



    return 0;
}