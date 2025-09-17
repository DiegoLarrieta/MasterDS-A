// LeetCode 771 Jewels and Stones

/*
You're given strings jewels representing the types of stones that are jewels,
and stones representing the stones you have. Each character in stones is a type of stone you have. 
You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".


Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Input: jewels = "z", stones = "ZZ"
Output: 0
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
// O(n + m) where n is the length of jewels and m is the length of stones
int numJewelsInStones(string jewels, string stones){

    // Create a hash map to store the jewels and their frequencies
    unordered_map<char,int> jewelMap;

    // Traverse the jewels string and add each jewel to the map with frequency 0
    for(char c : jewels){
        jewelMap[c] = 0;
    }

    // Traverse the stones string and check if its a jewel 
    for(char c : stones){
        if(jewelMap.find(c) != jewelMap.end()){
            jewelMap[c]++; // If its a jewel increase its frequency
        }
    }
    // Now we need to sum the frequencies of all jewels
    int totalJewels = 0;
    
    // Pair means the whole key-value pair in the map
    // pair.rirst is the key
    // pair.second is the value
    for(auto &pair : jewelMap){
        totalJewels += pair.second; // Sum the frequencies
    }

    return totalJewels;

}