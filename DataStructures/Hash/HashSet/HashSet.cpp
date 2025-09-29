#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// Print Hash Set
void printSet(const unordered_set<string> & set){
    // Iterate through the set and print elements
    for(const auto &element : set){
        cout<< element << " ";
    }
    cout<<endl;
}

int main(){
    // Declare the hash set
    unordered_set<string> fruits;

    // 1. Insertion O(1)
    fruits.insert("Apple");
    fruits.insert("Banana");
    fruits.insert("Orange");
    fruits.insert("Mango");

    // emplace is similar to insert but can be more efficient in some cases like with complex objects
    fruits.emplace("Grapes"); 
    fruits.insert("Apple"); // Duplicate, will not be added

    cout << "Fruits in the set: "<< endl;
    printSet(fruits);

    // 2. Access - Not applicable for sets as they are unordered collections of unique elements

    // 3. Search O(1)
    if(fruits.find("Banana") != fruits.end()){
        cout << "Banana is in the set." << endl;
    }else{
        cout << "Banana is not in the set." << endl;
    }
    // if pineapple == fruits.end() then pineapple is not in the set
    if(fruits.find("Pineapple") != fruits.end()){
        cout << "Pineapple is in the set." << endl;
    }else{  
        cout << "Pineapple is not in the set." << endl;
    }
    cout << endl;

    // 4. Update - Not applicable for sets as they do not store key-value pairs
    // You cant delete , you can only remove and add new elements

    // 5. Deletion O(1)
    cout << "Removing Orange from the set."<<endl;
    fruits.erase("Orange"); // Remove Orange
    printSet(fruits);
    cout << endl;

    // 6. Size O(1)
    cout << "Number of fruits in the set: " << fruits.size() << endl;
    return 0;
}