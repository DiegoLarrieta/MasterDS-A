// Leetcode 424 - Longest Repeating Character Replacement

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
// O(n) time complexity
// O(1) space complexity
int characterReplacement(string s, int k) {

    // Initialize longest to track the longest valid substring 
    int maxLength = 0;

    // Initialize the left pointer
    int left = 0;

    // Create an array counts of size 26 to track the frequency of each character in the current window
    vector<int>counts(26,0);

     // Initialize maxCount to track the maximum frequency of a single character in the current window
    int maxCount = 0;

    // Start the sliding window
    for(int right = 0 ; right < s.size(); right++){
        // Increment the count of the character at right
        // Esto convierte el carácter a un índice entre 0 y 25,
        // y luego incrementa el conteo de ese carácter en el array counts.
        maxCount = max(maxCount, ++counts[s[right] - 'A']);

        // Check if the current window is valid
        while((right - left + 1) - maxCount > k){
            // If the window is not valid shrink it from the left

            // Decrement the value at the left pointer in the counts array
            counts[s[left] - 'A']--; 

            left++;
        } 
        // Update the longest valid substring length if the current window is valid
        maxLength = max(maxLength, right - left +1);
    }
    return maxLength; 

}