#include <iostream>
#include <cassert>

class Solution {
public:
    int totalNQueens(int n) {
        
    }
};

/*
    assuming n = 2, start first queen at first cell
    1 0
    0 0
    Then try and place the next queen
    1 0 
    1 0 -> invalid
    backtrack and move first queen
    0 1
    1 0 -> invalid
    can't backtrack anymore
    0 1
    0 1 -> invalid too
    return 0

    assuming n = 4
    0 1 0 0     0 0 1 0
    0 0 0 1     1 0 0 0
    1 0 0 0     0 0 0 1
    0 0 1 0     0 1 0 0
*/

int main() {
    Solution solution;
    
    assert(solution.totalNQueens(4) == 2);
    assert(solution.totalNQueens(1) == 1);

    std::cout << "All tests passed!";
    return 0;
}