#include <iostream>
#include <cassert>
#include <unordered_map>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        std::unordered_map<char,int> encounteredChars;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); ++right) {
            ++encounteredChars[s[right]];

            while (encounteredChars[s[right]] > 2) {
                --encounteredChars[s[left]];
                ++left;
            }

            ans = std::max(ans, right - left + 1);
        }  

        return ans;
    }
};
/*

*/

int main() {
    Solution solution;

    std::string s1 = "bcbbbcba";
    int ans1 = 4;
    assert(solution.maximumLengthSubstring(s1) == ans1);
    
    std::string s2 = "aaaa";
    int ans2 = 2;
    assert(solution.maximumLengthSubstring(s2) == ans2);


    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}