#include <iostream>
#include <unordered_map> // hash map
#include <string>

using namespace std;

// Print Hash Map
void printMap(const unordered_map<string, int> &map){
    // Iterate through the map and print key-value pairs
    for(auto &pair : map){
        //pair. first is the key | pair.second is the value
        cout << pair.first << " -> " << pair.second << endl;
    }
    cout << endl;
}

int main(){

    // Declare the hasp map
    // Key: string (name)
    // Value: int (age)

    unordered_map<string, int> people;

    // 1. Insertion O(1)

    // - Method 1: Using [] operator
    people["Alice"] = 25; // Add key alice with value 25
    people["Bob"] = 30;

    // - Method 2: Using insert() method
    people.insert({"Charlie", 28});
    people.insert(make_pair("Diana", 22)); // make_pair : Inserts the pair only if the key "Diana" does not already exist.
    people.insert(make_pair("Alice", 35)); // This will not update Alice's age since "Alice" already exists

    cout << "Initial map:" << endl;
    printMap(people);


    // 2. Access O(1)
    cout << "Alice age is: " << people["Alice"] << endl; // Access value by key
    cout << "Bob age is: " << people.at("Bob") << endl; // Access value by key using at()
    cout << endl;

    // 3. Search O(1)
    // .find() method returns an iterator to the element if found, or map.end() if not found
    if(people.find("Charlie") != people.end()){
        cout<< "Charlie exists with the age: "<<people["Charlie"]<<endl;
    }else{
        cout<<"Charlie not found"<<endl;
    }

    if(people.find("Eve") != people.end()){
        cout<< "Eve exists with the age: "<<people["Eve"]<<endl;
    }
    cout<<endl;

    // 4.Update O(1)
    cout << "Updating ages Alice & Bob" << endl;
    people["Alice"] = 26; // Update Alice's age
    people.at("Bob") = 31; // Update Bob's age using at()
    printMap(people);

    // 5. Deletion O(1)
    cout<<"Deleting people Diana"<<endl;
    people.erase("Diana"); // Remove Diana from the map
    printMap(people);

    // 6. Size O(1)
    cout << "Size of the map: " << people.size() << endl;

}