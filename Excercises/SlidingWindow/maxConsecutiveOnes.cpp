// LeetCode 1004 - Max Consecutive Ones III
/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array 
if you can flip at most k 0's.

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

#include <iostream>
#include <vector>

using namespace std;

// O(n) time complexity and O(1) space complexity
int longestOnes(vector<int> &nums, int k){

    // Initialize the maximum widow length of consecutive 1's
    int maxWindow = 0;

    // Initialize the number of zeros in the current window
    int numZeros = 0;

    // Initialize the left pointer of the sliding window
    int left = 0;

    // Iterate through the array with the right pointer
    for (int right = 0; right < nums.size(); right++){
        // If we encounter a 0, we increment the count of zeros
        if(nums[right] == 0){
            numZeros++;
        }

        // If the number of zeros exceeds k, we need to shrink the window from the left
        while(numZeros > k){
            // If the current element on the left window is 0, we decrement the count of zeros
            if(nums[left] == 0){
                numZeros--;
            }
            // Move the left pointer to the right to shrink the window
            left++;
        }
        // Update the maximum window size
        maxWindow = max(maxWindow, right - left + 1); 
    }
    return maxWindow;
}