#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::unordered_map<char, int> map1;
        std::unordered_map<char, int> map2;

        for (auto& letter : s1) {
            ++map1[letter];
        }

        int n = s1.size();
        for (int idx = 0; idx < n; ++idx) {
            ++map2[s2[idx]];
        }

        for (int left = n; left < s2.size() - n; ++left) {

        }
    }
};

/*
    Man I'm fuckin dumb, just use a sliding window approach

    Add characters of s1 to a hash map, set won't work in case of duplicates
    Iterate through each character in s2 and check to see if it is a letter in the map. 
        If there is a match, remove the letter from the map and store it in a vector or something
            If the map is empty, that means we found a permutation and can return true
        If there is not a match, add all the characters from the storage vector back into the map
    
    Return false if we reach the end of s2 without finding a match

    Need to handle the case where we find a duplicate character that doesn't have any characters "left" in the count. Need to add characters back until the count is back to 1.
*/

int main() {
    Solution solution;
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";
    bool ans1 = true;

    std::string s3 = "ab";
    std::string s4 = "eidboaoo";
    bool ans2 = false;

    std::string s5 = "adc";
    std::string s6 = "dcda";
    bool ans3 = true;
    auto t0 = std::chrono::high_resolution_clock::now();
    bool test1 = solution.checkInclusion(s1, s2);
    bool test2 = solution.checkInclusion(s3, s4);
    bool test3 = solution.checkInclusion(s5, s6);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}

