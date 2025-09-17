// Leetcode 383

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed
by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.


Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
// O(N + M) where N is the length of ransomNote and M is the length of magazine
bool canConstruct(string ransomNote, string magazine){

    // Create a hash map to store the character and its frequency

    unordered_map<char, int > charCount;

    // Traverse the magazine and count the frequency of each character
    for(char c : magazine){
        charCount[c]++;
    }

    // Traverse the ransom note and check if we have enough characters in the magazine

    for(char c : ransomNote){

        // If the character its not in the map or its frequency is 0, return false
        if(charCount.find(c) == charCount.end() || charCount[c] == 0){
            return false;
        }

        // Decrease the frequency of the character
        charCount[c]--;
    }
    return true;
}