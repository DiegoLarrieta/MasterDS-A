// Leetcode 128 Longest Consecutive Sequence

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int> &nums){
    // Step 1 , create hash set
    unordered_set<int> numSet;

    // Step 2 , iterate trough the array and add the elements to the hash set
    for(int num : nums){
        numSet.insert(num);
    }

    int longestStreak = 0;

    // Step 3, iterate though the hash set and check if the current element is the start of a sequence
    // To do this we have to check if the previous of the current element exists in the hash set
    // Eg [ 1 , 2 , 3 , 4] => is 0 in the hash set ? No , then 1 is the start of a sequence

    for(int num : numSet){
        if(numSet.find(num - 1) == numSet.end()){
            //  == numSet.end() we check if the element is not in the hash set
            int currentNum = num;
            int currentStreak = 1;

            // Step 4, he have found the start of a sequence , now we have to find the length of the sequence
            // By this we have to check if the next element of current exists in the hash set
            while(numSet.find(currentNum + 1) != numSet.end()){
                // If the next element exists in the hash set , we increment the current number and the current streak
                currentNum += 1;
                currentStreak += 1;
            }
            // Step 5, we update the longest streak if the current streak is greater than the longest streak
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}