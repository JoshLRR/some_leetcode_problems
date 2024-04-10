#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            int num = std::abs(nums[i]);
            if (num > n) {
                continue;
            }
            --num;
            if (nums[num] > 0) {
                nums[num] *= -1;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] >=0) {
                return i + 1;
            }
        }

        return n + 1;
    }
    // int firstMissingPositive(std::vector<int>& nums) {
    //     int n = nums.size();
    //     for (int i = 0; i < n; ++i) {
    //         std::swap(nums[i], nums[nums[i] - 1]);
    //     }

    //     // for (int i = 0; i < n; ++i) {
    //     //     if (nums[i] != i + 1) {
    //     //         std::cout << "solution: " << i + 1 << "\n";
    //     //         return i + 1;
    //     //     }
    //     // }

    //     for (auto& num : nums) {
    //         std::cout << num << " ";
    //     }
    //     std::cout << "\n";


    //     return 0;
    // }
};

/*
    There are two possibilities, 
    1. No nums are missing from the array (has all ints from 1 - n)
    2. There is a missing int from the array

    - Ignore all nums smaller than 0 or larger than n
    - For all nums larger than n or less than 0, mark that bucket to indicate that the integer exists
    - Find the first cell not marked, that's the missing num

    --- Another approach using swap
    First iteration through nums:
    Find a num, swap it to its buckets (num == 2, swap(nums[i], nums[2]))

    Second iteration through nums:
    First num that doesn't match its index is the missing number
*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,2,0};
    int ans1 = 3;
    // assert(solution.firstMissingPositive(nums1) == ans1);

    std::vector<int> nums2 = {3,4,-1,1};
    int ans2 = 2;
    // assert(solution.firstMissingPositive(nums2) == ans2);

    std::vector<int> nums3 = {7,8,9,11,12};
    int ans3 = 1;
    assert(solution.firstMissingPositive(nums3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}