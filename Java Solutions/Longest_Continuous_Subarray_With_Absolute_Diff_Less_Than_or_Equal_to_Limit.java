import java.util.ArrayDeque;
import java.util.Deque;

class Longest_Continuous_Subarray_With_Absolute_Diff_Less_Than_or_Equal_to_Limit {

    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxHeap = new ArrayDeque<>();
        Deque<Integer> minHeap = new ArrayDeque<>();
        int idx = 0, jdx; 

        for (jdx = 0; jdx < nums.length; ++jdx) {
            while (!maxHeap.isEmpty() && nums[jdx] > maxHeap.peekLast()) maxHeap.pollLast();
            while (!minHeap.isEmpty() && nums[jdx] < minHeap.peekLast()) minHeap.pollLast();

            maxHeap.add(nums[jdx]);
            minHeap.add(nums[jdx]);

            if (maxHeap.peek() - minHeap.peek() > limit) {
                if (maxHeap.peek() == nums[idx]) maxHeap.poll();
                if (minHeap.peek() == nums[idx]) minHeap.poll();
                ++idx;
            }
        }

        return jdx - idx;
    }

    public static void main(String[] args) {
        Longest_Continuous_Subarray_With_Absolute_Diff_Less_Than_or_Equal_to_Limit solution = new Longest_Continuous_Subarray_With_Absolute_Diff_Less_Than_or_Equal_to_Limit();

        int[] nums1 = {8,2,4,7};
        int limit1 = 4;
        int ans1 = 2;

        int[] nums2 = {10,1,2,4,7,2};
        int limit2 = 5;
        int ans2 = 4;

        int[] nums3 = {4,2,2,2,4,4,2,2};
        int limit3 = 0;
        int ans3 = 3;

        long startTime = System.nanoTime();
        int test1 = solution.longestSubarray(nums1, limit1);
        int test2 = solution.longestSubarray(nums2, limit2);
        int test3 = solution.longestSubarray(nums3, limit3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}