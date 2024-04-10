#include <iostream>
#include <cassert>

class Solution {
public:
    int minOperations(int k) {
        int ans = INT_MAX;
        int increment = 0;
        int duplicate = 0;

        if (k == 1) return 0;

        for (int i = 1; i <= k / 2; ++i) {
            increment = i - 1;
            if (1 + increment == k) {
                ans = std::min(ans, increment);
            }
            duplicate = k / i;
            if (k % i == 0) {
                std::cout << "found perfect division: " << "k, i = " << k << "," << i << "\n";
                ans = std::min(ans, (k / i) -1 + increment);
            }

            std::cout << "k / i: " << k / i << "\n";
            ans = std::min(ans, increment + duplicate);
        }


        std::cout << ans << "\n";
        return ans;
    }
};

/*

Start off with an array nums = [1]

2 available operations:
    - Double any element in nums
    - Duplicate any element in the array and add it to the end

Find minimum number of operations to have the sum of nums greater than or equal to k

Input: k = 11
Output: 5
Explanation:
We can do the following operations on the array nums = [1]:

    Increase the element by 1 three times. The resulting array is nums = [4].
    Duplicate the element two times. The resulting array is nums = [4,4,4].

The sum of the final array is 4 + 4 + 4 = 12 which is greater than or equal to k = 11.
The total number of operations performed is 3 + 2 = 5.

------------------------------------------------------------------------------------------

*/

int main() {
    Solution solution;
    int k1 = 11;
    int ans1 = 5;
    assert(solution.minOperations(k1) == ans1);

    int k2 = 1;
    int ans2 = 0;
    assert(solution.minOperations(k2) == ans2);

    int k3 = 2;
    int ans3 = 1;
    assert(solution.minOperations(k3) == ans3);

    int k4 = 4;
    int ans4 = 2;
    assert(solution.minOperations(k4) == ans4);


    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}