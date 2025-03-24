#include <iostream>
using namespace std;

// Function to print the array
void printArray(int arr[], int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main (){

    // 1. Array declaration and initialization
    // [] =  size of the array
    // {} =  values of the array

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = 10;

    cout<< "Initial array: ";
    printArray(arr, size);

    cout<<"----------------------------------"<<endl;

    // 2. Accessing elements of an array
    cout<< "Accesing elements: "<<endl;
    cout<<"Element at index 0: "<<arr[0]<<endl;
    cout<<"Element at index 5: "<<arr[5]<<endl;

    cout<<"----------------------------------"<<endl;


    // 3. Inserting an element in an array
    cout<<"Inserting 10 at index 2: "<<endl;
    int insertIndex = 2;
    int valueToInsert = 10;
    for(int i = size ;  i > insertIndex; i--){
        arr[i] = arr[i-1];
    }
    arr[insertIndex] = valueToInsert;
    size++;
    printArray(arr, size);

    cout<<"----------------------------------"<<endl;


    // 4. Deleting an element from an array

    cout << "Deleting element at index 3:" << endl;
    int deleteIndex = 3;
    for (int i = deleteIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    size--;
    printArray(arr, size);

    cout<<"----------------------------------"<<endl;


    // 5. Searching an element in an array
    cout << "Searching for element 10"<<endl;
    int searchValue = 10;
    bool found = false;
    for(int i = 0; i < size ; i++){
        if (arr[i] == searchValue){
            cout << "Element " << searchValue<< " found at index: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found){
        cout << "Element " << searchValue << " not found in the array" << endl;
    }

    return 0;



}