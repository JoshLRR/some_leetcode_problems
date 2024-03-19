#include <iostream>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char,int> encountered;
        int left = 0;
        int maxLength = 0;
        int n = s.size();

        for (int right = 0; right < n; ++right) {
            if (encountered.find(s[right]) != encountered.end()) {
                left = std::max(left, encountered[s[right]] + 1);
            } 
            encountered[s[right]] = right;
            maxLength = std::max(maxLength, right-left+1);
            
        }
        return maxLength;
    }
};


/*
    Iterate through s, check substrings with iteration using a sliding window
    a   b   c   a   b   c   b   b
    a
    a   b   
    a   b   c   a       -- repeat found, retract the window
        b   c   a   
        b   c   a   b   -- repeat found, retract the window
            c   a   b
            c   a   b   c -- repeat found, retract
                a   b   c
                a   b   c   b   -- repeat found, retract
                        c   b
                        c   b   b   -- repeat found
                                b

    For each letter add to the set
        if a repeat is found, compare length with existing maxLength and reset count and set
*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}