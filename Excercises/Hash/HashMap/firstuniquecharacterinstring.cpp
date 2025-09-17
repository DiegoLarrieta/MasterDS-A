// LeetCode 387 First Unique Character in a String
/*
Example 1:

Input: s = "leetcode"
Output: 0
Explanation: The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s){
    // Create a hash map to store the frequency of each character

    unordered_map<char,int> charCount;

    // Traverse the string and count the frequency of each character
    for(char c : s){
        charCount[c]++;
    }
    // Traverse the string again to find the first unique character
    for(char c : s){
        if(charCount[c] == 1){
            return s.find(c); // Return the index of the first unique character
        }
    }
    return -1;
}