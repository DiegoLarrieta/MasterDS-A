// ;eetcode 11. Container With Most Water

#include <iostream>
#include <vector>
#include <algorithm> // for min and max

using namespace std;
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxArea(vector<int> &height){
    // Declare the high and low pointers 
    int low = 0;
    int high = height.size()-1;

    // Variable to store the maximum area found
    int max_area = 0;

    while(low < high){
        // Calculate the width of thge container
        int width = high - low;

        // Calculate the height of the container, which is the minimum of the two heights
        int container_height = min(height[low], height[high]);

        // Calculate the area if the container
        int area = width * container_height;

        // Update max_area if the current area is greater
        max_area = max(max_area, area);

        // adjusrt the pointers
        if(height[low] < height[high]){
            low++; // Move the low pointer to the right to try to find a taller line
        }else{
            high--; // Move the high pointer to the left to try to find a taller line
        }
    }
}