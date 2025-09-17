// Leetcode 217

/*
Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

Example 1
Input: nums = [1,2,3,1]
Output: true

Example 2
Input: nums = [1,2,3,4]
Output: false
*/

#include <iostream>
#include <vector>
#include <unordered_map> // Hash map
using namespace std;
// Complexity O(N) where N is the size of the input array
bool containsDuplicate(vector<int>& nums) {

    // Create hashmap to store the frequency of elements
    unordered_map<int,int> frequency;

    // Traverse the array
    for(int i = 0 ; i < nums.size() ; i++){
        
        // If the element is already in the set, return true
        if(frequency.find(nums[i]) != frequency.end()){
            return true; // Duplicate found
        }
        // If the element is not in the set, add it with frequency 1
        frequency[nums[i]] = 1;
    }
    return false; // No duplicates found
}