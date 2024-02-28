#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<std::vector<int>> ans;
    void dfs(std::vector<int>& currentCombo, int& target, std::vector<int>& candidates, int startIndex) {
        // Base case -- if accumulate currentCombo == target, add currentCombo to ans
        int currSum = std::accumulate(currentCombo.begin(), currentCombo.end(), 0);
        if (currSum == target) {
            ans.push_back(currentCombo);
            return;
        } 

        if (currSum > target) { // If currentCombo exceeds target, that path is invalid
            return;
        }

        // Recursive Case -- try all candidates
        for (int i = startIndex; i < candidates.size(); ++i) {
            currentCombo.push_back(candidates[i]);
            dfs(currentCombo, target, candidates, i);
            currentCombo.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int> candidates, int target) {
        int n = candidates.size();
        std::vector<int> currentCombo;
        dfs(currentCombo, target, candidates, 0);
        

        return ans;
    }
};

/*
    For each candidate, use a decision tree
    Recursively check which combos work
*/

int main() {

    Solution solution;
    std::vector<std::vector<int>> expected1 = {{2,2,3},{7}};
    assert(solution.combinationSum({2,3,6,7}, 7) == expected1);
    // std::vector<std::vector<int>> expected2 = {{2,2,2,2},{2,3,3},{3,5}};
    // assert(solution.combinationSum({2,3,5}, 8) == expected2);

    std::cout << "All tests passes!";
    return 0;
}