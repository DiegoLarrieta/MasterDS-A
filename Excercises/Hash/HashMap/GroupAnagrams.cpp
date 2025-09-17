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

vector<vector<string>> groupAnagrams(vector<string> &strs){
    // Create a hash map to store the anagrams 
    // Key: sorted string
    // Value: vector of strings that are anagrams
    unordered_map<string,vector<string>> anagramMap;

    // Traverse the array of strings
    for(string s : strs){
        
    }
}