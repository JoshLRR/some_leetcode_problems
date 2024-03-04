#include <iostream>
#include <cassert>

class Solution {
public:
    std::vector<int> resultArray(std::vector<int>& nums) {
        std::vector<int> arr1;
        std::vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        for (auto& val : arr1) {
            std::cout << val << " ";
        }
        std::cout << "\n";

        return arr1;
    }
};

/*
    1-indexed array -- jk the problem description is a lie. It was 0-indexed.
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {2, 1, 3};
    std::vector<int> ans1 = {2,3,1};
    std::vector<int> nums2 = {5,4,3,8};
    std::vector<int> ans2 = {5,3,4,8};

    assert(solution.resultArray(nums1) == ans1);
    assert(solution.resultArray(nums2) == ans2);

    std::cout << "All tests passed!";
    return 0;
}