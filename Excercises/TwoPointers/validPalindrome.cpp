// Leetcode 125 Valid Palindrome

#include <iostream>
#include <string>
#include <cctype> // for isalnum and tolower

using namespace std;

bool isPalindrome(string s){
    // Create a high and a low pointer
    int low = 0;
    int high =  s.size()-1;

    // if the string is empty returns true
    if(s.empty()){
        return true;
    }


    while(low <= high){
       // !isalnum(s[low]) is to check if the character is not alphanumeric like blank spaces, comas etc...
        while(low < high && !isalnum(s[low])){
            low++;
        }
        // if hihg is not alphanumeric decrease the high pointer
        while(low < high && !isalnum(s[high])){
            high--;
        }

        // Now lets compare the characters , we use tolower to make the comparison case insensitive
        if(low < high && tolower(s[low]) != tolower(s[high])){
            return false; // If they are not equal return false
        }
        low++;
        high--;
    }
    return true;
}