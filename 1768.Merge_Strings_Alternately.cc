#include <iostream>
#include <cassert>
#include <sstream>
class Solution {
public:
    // std::string mergeAlternately(std::string word1, std::string word2) {
    //     std::stringstream ss;
    //     int m = word1.size();
    //     int n = word2.size();
    //     int currIdx = 0;
    //     for (int i = 0; i < std::min(m,n); ++i) {
    //         ss << word1[i];
    //         ss << word2[i];
    //         currIdx = i;
    //     }
    //     ++currIdx;
    //     // std::cout << currIdx << "\n";

    //     for (int i = currIdx; i < std::max(m,n); ++i) {
    //         if (m > n) {
    //             ss << word1[i];
    //         } else {
    //             ss << word2[i];
    //         }
    //     }
        
    //     // std::cout << ss.str() << "\n";
    //     return ss.str();
    // }
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string ans;
        int m = word1.size();
        int n = word2.size();
        ans.reserve(m + n);

        int minLength = std::min(m,n);
        for (int i = 0; i < minLength; ++i) {
            ans += word1[i];
            ans += word2[i];
        }

        if (m > n) {
            ans += word1.substr(minLength);
        } else {
            ans += word2.substr(minLength);
        }

        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    std::string word1 = "abc";
    std::string word2 = "pqr";
    std::string ans1 = "apbqcr";
    assert(solution.mergeAlternately(word1, word2) == ans1);

    std::string word3 = "ab";
    std::string word4 = "pqrs";
    std::string ans2 = "apbqrs";
    assert(solution.mergeAlternately(word3, word4) == ans2);

    std::string word5 = "abcd";
    std::string word6 = "pq";
    std::string ans3 = "apbqcd";
    assert(solution.mergeAlternately(word5, word6) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}