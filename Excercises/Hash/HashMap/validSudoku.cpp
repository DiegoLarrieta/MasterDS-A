// LeetCode 36

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
// O(1) since the board size is fixed 9x9
bool isValidSudoku(vector<vector<char>>&board){

    // VALIDATE ROWS
    // First we need to iterate through each row
    for(int i = 0; i < 9 ; i++){
        // Crete a hash set to store the characters we have seen so far
        unordered_set<char>seenRow;
        // Now we need to iterate through each column in the row
        for(int j = 0; j < 9 ; j++){
            // Get the current character
            char current = board[i][j];

            // If the character is not empty
            if(current != '.'){
                // If we have seen the character before, return false
                if(seenRow.find(current) != seenRow.end()){
                    return false; // Duplicate found
                }else{
                    // If we have not seen the character before, add it to the set
                    seenRow.insert(current);
                }
            }
        }
    }

    // VALIDATE COLS
    // First we need to iterate through each column
    for(int j = 0; j < 9; j++){
        // Create a hash set to store the characters we have seen so far
        unordered_set<char> seenCol;
        // Now we need to iterate through each row inthe column
        for(int i = 0; i<9; i++){
            // Get the current character
            char current = board[i][j];

            // If the character is not empty
            if(current != '.'){
                // If we have seen the character before, return false
                if(seenRow.find(current) != seenRow.end()){
                    return false; // Duplicate found
                }else{
                    // If we have not seen the character before, add it to the set
                    seenRow.insert(current);
                }
            }
        }
    }

    // VALIDATE BOXES
    // We have 9 boxes in total
    for(int square = 0; square < 9; square++){
        unordered_set<char> seenBox;
        // Each box has 3 rows and 3 columns
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                // Calculate the row and column index of the current cell in the box
                // For example, for the first box (square = 0), the row and column indices are (0,0), (0,1), (0,2), (1,0), (1,1), (1,2), (2,0), (2,1), (2,2)
                int row = (square / 3) * 3 + i; // Get the row index
                // 
                int col = (square % 3) * 3 + j; // Get the column index
                char current = board[row][col];
                if(current != '.'){
                    if(seenBox.find(current) != seenBox.end()){
                        return false; // Duplicate found
                    }else{
                        seenBox.insert(current);
                    }
                }
            }
        }
    }
    return true;
}