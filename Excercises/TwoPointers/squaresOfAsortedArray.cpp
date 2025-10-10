// Leetcode 977 Squares of a Sorted Array

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int> &nums){

    // Create 2 pointers 

    // left pointer 
    int left = 0;

    // right pointer 
    int right = nums.size()-1;

    // Create a result vector with the same size as numa 
    vector<int> result(nums.size());

    // Position to fill in the result vector, starting from the end
    int insertPos = nums.size() - 1;

    while(left <= right){
        // If the absolute value at the left pointer is greater than the absolute value at the right pointer
        if(abs(nums[left]) > abs(nums[right])){
            // Because left is great we square the value and insert it in the result vector
            //insertPos-- means that after inserting the value we move the position to the left
            result[insertPos--] = nums[left] * nums[left];
            left++; // Move the left pointer to the right
        }else{
            // If the abs value of right is greater we do the same, square it, insert it and move the pointer
            result[insertPos--] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}