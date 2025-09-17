// Leetcode 169

/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.


Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//O(N)
int majorityElement(vector<int> &nums){

    // Create a hash map to store the frequency 
    unordered_map<int,int> frequency;

    // Obtain the majority count
    int majorityCount = nums.size() / 2;

    // Traverse the array and add the count 
    for(int i = 0; i<nums.size(); i++){
        frequency[nums[i]]++;

        // If the frequency of the current element is greater than majorityCount return it
        if(frequency[nums[i]] > majorityCount){
            return nums[i];
        }
    } 
}