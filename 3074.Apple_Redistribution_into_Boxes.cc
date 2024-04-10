#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

class Solution {
public:
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        std::sort(capacity.begin(), capacity.end(), std::greater<>());
        int totalApples = std::accumulate(apple.begin(), apple.end(), 0);
        // int boxCount = 0;
        int boxIndex = 0;

        while (totalApples > 0) {
            totalApples -= capacity[boxIndex];
            ++boxIndex;
            // ++boxCount;
        }

        // std::cout << boxCount << "\n";
        return boxIndex;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> apple1 = {1,3,2};
    std::vector<int> capacity1 = {4,3,1,5,2};
    int ans1 = 2;
    assert(solution.minimumBoxes(apple1, capacity1) == ans1);

    std::vector<int> apple2 = {5,5,5};
    std::vector<int> capacity2 = {2,4,2,7};
    int ans2 = 4;
    assert(solution.minimumBoxes(apple2, capacity2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}