#include <iostream>
#include <cassert>
#include <sstream>
#include <unordered_set>
class Solution {
public:
    std::string customSortString(std::string order, std::string s) {
        std::stringstream ss;
        std::unordered_map<char, int> encountered;
        // std::unordered_set<char> seen(s.begin(), s.end());
        
        for(auto& letter : s) {
            if (encountered.find(letter) != encountered.end()) {
                ++encountered[letter];
            } else {
                encountered[letter] = 1;
            }
        }

        for(auto& letter : order) {
            if (encountered.find(letter) != encountered.end()) {
                while(encountered[letter] > 0) {
                    ss << letter;
                    --encountered[letter];
                }

                if (encountered[letter] == 0) {
                    encountered.erase(letter);
                }
            }
        }

        // for(auto& letters : encountered) {
        //     std::cout << letters.first << " : " << letters.second;
        // }

        // std::cout << "\n";

        for (auto& letter : encountered) {
            for (int i = 0; i < letter.second; ++i) {
                ss << letter.first;
            }
        }
        
        // std::cout << ss.str() << "\n";
        return ss.str();
    }
};

/*
    Create an unordered set to hold the chars of s1
    Iterate through order1, append those chars to a stringstream and remove them from the set of s1 chars
    Append remaining chars in s1
    Convert stringstream to string and return
*/

int main() {
    Solution solution;

    std::string order1 = "cba";
    std::string s1 = "abcd";
    std::string ans1 = "cbad";
    assert(solution.customSortString(order1,s1) == ans1);

    std::string order2 = "bcafg";
    std::string s2 = "abcd";
    std::string ans2 = "bcad";
    assert(solution.customSortString(order2,s2) == ans2);

    std::string order3 = "kqep";
    std::string s3 = "pekeq";
    std::string ans3 = "kqeep";
    assert(solution.customSortString(order3,s3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}