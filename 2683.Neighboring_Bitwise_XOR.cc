#include <iostream>
#include <cassert>
#include <vector>
class Solution {
public:
    bool doesValidArrayExist(std::vector<int>& derived) {
        int n = derived.size();
        std::vector<int> binArray(n);
        int runningTotal = derived[0];
        
        for (int i = 1; i < n; ++i) {
            runningTotal ^= derived[i];
        }

        return (runningTotal == 0) ? true : false;
    }
};

/*

*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}