#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum > target) {
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    std::vector<int> triplet = {nums[i], nums[left], nums[right]};
                    ans.push_back(triplet);

                    while (left < right && nums[left] == triplet[1]) {
                        ++left;
                    }

                    while (right > left && nums[right] == triplet[2]) {
                        --right;
                    }
                }
            }
            while (i+1 < n && nums[i + 1] == nums[i]) {
                ++i;
            }
        }

        return ans;
    }
};

/*
    i != j
    i != k
    j != k
    nums[i] + nums[j] + nums[k] == 0

    Two pointer solution
    Start by sorting the nums array
    By fixing one value (i), the solution logic becomes the same as 2sum
    Iterate through each value nums[i], for each value we have two pointers;
        left is the value to the right of i
        right starts at the end and moves to the left
    For each iteration, sum nums[left] and nums[right] 
    Set the target to the negative of nums[i]
    If the negative of nums[i] is equal to the sum of left and right, we have found a total sum of 0
        ex nums[i] = -5 -> 5, nums[left] = 2, nums[right] = 3
        This works because nums is sorted
    After checking to see if the current iteration works, we need to skip over all the duplicates

    Time complexity: O(n^2) -- The sort operation is O(n logn), but the for loop in the worst case will have the left and right pointers iterate through n-i values, so the outer for loop has a complexity of O(n) and the inner loop has a complexity of O(n), giving O(n^2);
    Space complexity: O(1) -- The output size scales at O(n), but we use a fixed amount of space for the solution
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> ans1 = {{-1,-1,2}, {-1,0,1}};
    assert(solution.threeSum(nums1) == ans1);

    std::vector<int> nums2 = {0,1,1};
    std::vector<std::vector<int>> ans2 = {};
    assert(solution.threeSum(nums2) == ans2);

    std::vector<int> nums3 = {0,0,0};
    std::vector<std::vector<int>> ans3 = {{0,0,0}};
    assert(solution.threeSum(nums3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}