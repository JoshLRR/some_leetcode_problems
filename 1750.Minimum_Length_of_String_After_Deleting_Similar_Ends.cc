#include <iostream>
#include <cassert>

class Solution {
public:
    int minimumLength(std::string& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right && s[left] == s[right]) { 
            char currChar = s[left];
            while (left <= right && s[left] == currChar) ++left; 
            while (left <= right && s[right] == currChar) --right; 
        }
        // The length of the remaining string is right - left + 1, but it can be negative if left > right (fully removed), hence max with 0
        return std::max(0, right - left + 1); 
    }
};

/*
    Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
    Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
    The prefix and the suffix should not intersect at any index.
    The characters from the prefix and suffix must be the same.
    Delete both the prefix and the suffix.
*/

int main() {
    Solution solution;
    std::string input1 = "ca";
    int ans1 = 2;
    assert(solution.minimumLength(input1) == ans1);

    std::string input2 = "cabaabac";
    int ans2 = 0;
    assert(solution.minimumLength(input2) == ans2);

    std::string input3 = "aabccabba";
    int ans3 = 3;
    assert(solution.minimumLength(input3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}