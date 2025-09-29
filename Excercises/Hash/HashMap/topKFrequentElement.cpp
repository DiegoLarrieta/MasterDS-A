// Leetcode 347 Top K Frequent Elements

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// O(N log N) where N is the number of elements in the nums array
vector<int>topKFrequent(vector<int> &nums,int k){
    // Create a hash map tp store the frequency of each element
    unordered_map<int,int> freq;

    // Traverse the nums array and store the frequency of each element in the map
    for(int num : nums){
        freq[num]++;// If its already in the map increase its frequency else add it to the map with frequency 1
    }

    // Now that he have all the elenments and their frequencies we need to sort by frequencies, but in hash we cant sort the frequencies
    // So we will create a pair vector to store the elements and their frequencies where pair.first is the element and pair.second is the frequency
    vector<pair<int,int>> freqVec;

    // Traverse the map and add each element and its frequency to the vector
    // Eg from this hash { 1:3, 2:2, 3:1 }  to this vector [ (3,1), (2,2), (1,3) ]
    for(const auto &pair : freq){
        freqVec.push_back({pair.second,pair.first}); // We push frequency first to sort by frequency later
    }
    // We sort the vector in descending order by frequency 3 > 2 > 1

    sort(freqVec.rbegin(),freqVec.rend());

    // Now we need to return the top k frequent elements
    vector<int> result;
    for(int i = 0; i < k; i++){
        result.push_back(freqVec[i].second); // We push the element not the frequency eg
    }

    return result;
}