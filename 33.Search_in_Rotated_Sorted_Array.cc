#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int pivotIndex = -2;
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while (left < right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // if (mid < n-1 && nums[mid] > nums[mid+1]) {
            //     pivotIndex = mid + 1;
            // } 
            // if (mid > 0 && nums[mid-1] > nums[mid]) {
            //     pivotIndex = mid;
            // }

            if (nums[right] > nums[mid]) {
                right = mid;
            } else if (nums[left]) {
                left = mid+1;
            }
        }

        pivotIndex = left;
        if (target > nums[n-1]) {
            left = 0;
            right = pivotIndex;
        } else if (target <= nums[n-1]) {
            left = pivotIndex;
            right = n-1;
        }

        while (left <= right) {
            int mid = left + (right-left) / 2;

            if (nums[mid] == target) {
                return mid;
            } 
            if (nums[mid] < target) {
                left = mid+1;
            } else if (nums[mid] > target) {
                right = mid-1;
            } 
        }
        
        return -1;
    }
};
/*
    Binary Search -- 
    Find pivot
    Find which side of pivot to search on
    Find target
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {4,5,6,7,0,1,2};
    int tar1 = 0;
    int ans1 = 4;
    assert(solution.search(nums1, tar1) == ans1);

    std::vector<int> nums2 = {4,5,6,7,0,1,2};
    int tar2 = 3;
    int ans2 = -1;
    assert(solution.search(nums2, tar2) == ans2);

    std::vector<int> nums3 = {1};
    int tar3 = 0;
    int ans3 = -1;
    assert(solution.search(nums3, tar3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}