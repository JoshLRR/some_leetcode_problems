#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mid < n-1 && nums[mid] > nums[mid+1]) return nums[mid+1];
            if (mid > 0 && nums[mid] < nums[mid-1]) return nums[mid];

            if (nums[mid] < nums[right]) {
                right = mid-1;
            } else if (nums[left]) {
                left = mid+1;
            }
        }

        return nums[left];
    }
};

/*
    Use binary search -- need to find the pivot
    First check if the values surrounding mid are the pivot
    if mid+1 < mid (example ... 6, 0, ...) mid+1 is the pivot
    if mid-1 > mid (example ... 6, 0, 1, ...) mid is the pivot

    Then check the extremities,
    if right > mid, we know the pivot is to the left of mid
    else if left even exists, then the pivot is to the right
*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {3,4,5,1,2};
    int ans1 = 1;
    assert(solution.findMin(nums1) == ans1);

    std::vector<int> nums2 = {4,5,6,7,0,1,2};
    int ans2 = 0;
    assert(solution.findMin(nums2) == ans2);

    std::vector<int> nums3 = {11,13,15,17};
    int ans3 = 11;
    assert(solution.findMin(nums3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}