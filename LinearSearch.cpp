#include <iostream>
using namespace std;

// Recorres todo el arreglo , complejidad O(N)
int linearSearch(int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
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
    int arr[] = {4, 2, 7 ,1 ,9};
    int size = 5;
    int target = 7;

    printArray(arr, size);

    int result = linearSearch(arr, size, target);
    if(result != -1){
        cout << "Element " << target <<" ound at index: " << result << endl;
    }else{
        cout << "Element not found" << endl;
    }
    return 0;
}