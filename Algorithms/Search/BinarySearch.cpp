#include <iostream>
using namespace std;

// Complejidad O(log N)
int binarySearch(int arr[], int size , int target){
    int left = 0;
    int right = size - 1; // size - 1 porque los indices empiezan en 0

    while(left <= right){
        
        int mid = left + (right - left) / 2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            left = mid + 1; //Buscar en la mitad derecha
        }else{
            right = mid - 1; //Buscar en la mitad izquierda
        }
    }
    return -1;
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Arreglo ordenado
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    printArray(arr, size);

    int result = binarySearch(arr, size, target);

    if(result != -1){
        cout << "Element " << target << " found at index: " << result << endl;
    }else{
        cout << "Element not found" << endl;
    }
    return 0;
}

