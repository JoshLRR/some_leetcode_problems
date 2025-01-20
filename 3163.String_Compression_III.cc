#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    std::string compressedString(std::string word) {
        std::string ans = "";

        for (int idx = 0; idx < word.size(); ++idx) {
            int letterCount = 1;
            char currLetter = word[idx];
            
            while(word[idx + 1] == currLetter) {
                ++letterCount;
                ++idx;
                
                if (letterCount >= 9) break;
            }

            ans += std::to_string(letterCount) + currLetter;
        }


        std::cout << ans << "\n";
        return ans;        
    }
};

/*

*/

int main() {
    Solution solution;
    std::string word1 = "abcde";
    std::string ans1 = "1a1b1c1d1e";

    std::string word2 = "aaaaaaaaaaaaaabb";
    std::string ans2 = "9a5a2b";

    auto t0 = std::chrono::high_resolution_clock::now();
    std::string test1 = solution.compressedString(word1);
    std::string test2 = solution.compressedString(word2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}