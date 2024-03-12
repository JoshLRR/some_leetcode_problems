#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
class Solution {
public:
    // bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    //         int n = s.size();
    //         std::vector<bool> dp(n+1, false);
    //         dp[0] = true;
    //         std::unordered_set<std::string> wordSet;

    //         for (auto& word : wordDict) {
    //             wordSet.insert(word);
    //         }

    //         for (int i = 1; i <= n+1; ++i) {
    //             for (int j = i-1; j >= 0; --j) {
    //                 if (dp[j]) {
    //                     std::string currWord = s.substr(j, i-j);
    //                     if (wordSet.find(currWord) != wordSet.end()) {
    //                         dp[i] = true;
    //                         break;
    //                     }
    //                 }
    //             }
    //         }
    //     // for (int i = 0; i < dp.size(); ++i) {
    //     //     if (dp[i]) std::cout << "t ";
    //     //     if (!dp[i]) std::cout << "f ";
    //     // }
    //     // std::cout << "\n";
    //     return dp[n];
    // };

    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int n = s.size();
        std::vector<bool> dp(n, false);
        dp[n] = true;

        for (int i = n-1; i >= 0; --i) {
            for (auto& word : wordDict) {
                if (i + word.size() <= n && s.substr(i, word.size()) == word) {
                    dp[i] = dp[i + word.size()];
                }
                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};

/*
    s = "leetcode"  wordDict = {"leet", "code"}

    -   l   e   e   t   c   o   d   e
    t   f   f   f   t   f   f   f   t
    -  
    -   -
    -   -   -
    -   -   -   - found leet
                    -
                    -   -
                    -   -   -
                    -   -   -   -   found code
    Add all words from wordDict into an unordered_set
    Iterate through s, for each char in s we look through prev chars until a word is found
        once a word is found we can set the ith index of the dp table to true and break the inner loop
        the if dp[j] is there to mark the end/start of words
    Return bool value at the end of the dp table

    OR do it without an unorderd set
    Work backwards through s, for each char, iterate through each word in wordDict
    If a word is found to have the same length, check the substring to see if the word is the same
    If so, a valid word has been found and we can mark dp[i] as true

    Return dp[0]

    Time complexity -- O(n * m * k) where n is the size of s, m is the number of words in wordDict, and k is the number of substring comparisons
    Space complexity -- O(n) -- we only require a dp table of size n
*/

int main() {
    Solution solution;
    std::string s1 = "leetcode";
    std::vector<std::string> wordDict1 = {"leet", "code"};
    bool ans1 = true;
    assert(solution.wordBreak(s1, wordDict1) == ans1);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}