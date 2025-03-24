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
using namespace std;

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
    int arr[] = {3, 1, 7, 11};
    int size = 4;

    // Usar std::boolalpha para imprimir true o false
    cout << boolalpha << checkIfExist(arr, size) << endl;

    return 0;
}