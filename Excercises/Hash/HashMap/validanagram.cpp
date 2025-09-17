// LeetCode 242 Valid Anagram

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Input: s = "anagram", t = "nagaram"
Output: true


Input: s = "rat", t = "car"
Output: false
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t){

    // Base default case , if the lenghts of the strings are diferrent it cannot be anagram

    if(s.length() != t.length()){
        return false;
    }

    // Create a hash map tp store the characters and their frequencies
    unordered_map<char, int> charCount;

    // Traverse the first string and count the frequency of each character
    for(char c : s){
        charCount[c]++;
    }
    
    // Traverse the second string and decrease the frequency of each character
    for(char c : t){
        charCount[c]--;

        // If the frequency becomes negative , it means is not an anagram
        if(charCount[c]<0){
            return false;
        }
    }
    return true; 
}