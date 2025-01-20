import java.util.Arrays;

class Minimum_Difference_Between_Largest_and_Smallest_Value_in_Three_Moves {

    public int minDifference(int[] nums) {
        int n = nums.length;
        if (n < 5) return 0;
        Arrays.sort(nums);

        int minDifference = Integer.MAX_VALUE;
        for (int idx = 0; idx < 4; ++idx) {
            minDifference = Math.min(minDifference, nums[n - 4 + idx] - nums[idx]);
        }

        return minDifference;
    }

    public static void main(String[] args) {
        Minimum_Difference_Between_Largest_and_Smallest_Value_in_Three_Moves solution = new Minimum_Difference_Between_Largest_and_Smallest_Value_in_Three_Moves();

        int[] nums1 = {5,3,2,4};
        int ans1 = 0;

        int[] nums2 = {1,5,0,10,14};
        int ans2 = 1;

        int[] nums3 = {3,100,20};
        int ans3 = 0;
        long startTime = System.nanoTime();
        int test1 = solution.minDifference(nums1);
        int test2 = solution.minDifference(nums2);
        int test3 = solution.minDifference(nums3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}