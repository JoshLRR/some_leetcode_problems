#include <stdio.h>
#include <assert.h>
#include <time.h>

#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {

    int nums1[] = {-1,0,3,5,9,12};
    int nums1Size = sizeof(nums1) / sizeof(int);
    int target1 = 9;
    int ans1 = 4;

    int nums2[] = {-1,0,3,5,9,12};
    int nums2Size = sizeof(nums2) / sizeof(int);
    int target2 = 2;
    int ans2 = -1;

    // Function calls go inside here
    clock_t t0 = clock(); 
    int test1 = search(nums1, nums1Size, target1);
    int test2 = search(nums2, nums2Size, target2);
    clock_t end = clock(); 

    double time = ((double)(end - t0) / CLOCKS_PER_SEC) * 1000;  // Time in ms

    printf("%d\n", test1);
    printf("%d\n", test2);

    assert(test1 == ans1);
    assert(test2 == ans2);

    printf(GREEN_TEXT "All tests passed in %.3f ms!\n" RESET_TEXT, time);

    return 0;
}
