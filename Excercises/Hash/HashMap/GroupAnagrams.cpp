// LeetCode 49 Group Anagrams

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Input: strs = [""]
Output: [[""]]


Input: strs = ["a"]
Output: [["a"]]
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// O(m * n) where m is the number of strings and n is the maximum length of a string
vector<vector<string>> groupAnagrams(vector<string> &strs){
    // Create a hash map to store the anagrams 
    // Key: string that represents the character count
    // Value: vector of strings that are anagrams
    unordered_map<string,vector<string>> anagramMap;

    // Traverse the array of strings
    for(const auto& s : strs){
        // Create a count array to store the frequency of each character
        vector<int> count(26,0); 

        // Traverse the string and count the frequency of each character
        for(char c : s){
            // 'a' = 0 , 'b' = 1 , 'c' = 2 , ... 'z' = 25
            // e.g. if c = 'b' , then count[1]++ 
            // This way we count the frequency of each character in the string
            // e.g. "bat" -> count[1] = 1 (b), count[0] = 1 (a) , count[19] = 1 (t)
            count[c - 'a']++;
        }
        // Create a key from the count array 
        //  0,1,0 -> "0,1,0"
        string key;

        // Concatenate the frequencies to create a unique key for each anagram group
        for(int i = 0 i < 26; i++){
            if( i > 0) key += ","; // We use #, as a separator to avoid ambiguity
            key  += to_string(count[i]); // Convert the frequency to string and concatenate
        }
        // Add the string to the corresponding anagram group in the map
        // Eeat -> 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 .push_back("eat")
        
        // anagramMap[key].push_back(s); FORMA LINDA DE HACERLO 
        if(anagramMap.find(key) != anagramMap.end()){
            anagramMap[key].push_back(s);
        }else{
            anagramMap[key] = {s};
        }
    }
    // Create a result vector to store the anagram groups
    vector<vector<string>> result;
    // Traverse the map and add each anagram group to the result vector
    for(auto &pair : anagramMap){
        result.push_back(pair.second);
    }
    return result;
}