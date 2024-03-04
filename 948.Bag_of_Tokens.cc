#include <iostream>
#include <cassert>
#include <numeric>

class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                ++score;
                ++left;
            } else if (power < tokens[left] && score >= 1 && right - left > 1) {
                power += tokens[right];
                --score;
                --right;
            } else {
                std::cout << score << "\n";
                return score;
            }
        }
        std::cout << score << "\n";
        return score;
    }
};

/* 
    Each token can be played one of the two following ways, but not both:
    FACE-UP: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
        if currPower >= tokens[i] --> currPower -= tokens[i] && ++score;
    FACE-DOWN: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
        if score >= 1, power += tokens[i] && --score;

    Sort and be greedy
*/

int main() {
    Solution solution;
    std::vector<int> tokens1 = {100};
    int power1 = 50;
    int ans1 = 0;
    std::vector<int> tokens2 = {200, 100};
    int power2 = 150;
    int ans2 = 1;
    std::vector<int> tokens3 = {100,200,300,400};
    int power3 = 200;
    int ans3 = 2;

    assert(solution.bagOfTokensScore(tokens1, power1) == ans1);
    assert(solution.bagOfTokensScore(tokens2, power2) == ans2);
    assert(solution.bagOfTokensScore(tokens3, power3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}