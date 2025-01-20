class Count_Numbers_of_Nice_Subarrays {
    
    public int numberOfSubarrays(int[] nums, int k) {
        int ans = 0;
        int left = 0;
        int validSubarrays = 0;
        int n = nums.length;

        for (int right = 0; right < n; ++right) {
            if ((nums[right] & 1) == 1) {
                --k;
                validSubarrays = 0;
            }

            while (k == 0) {    
                k += nums[left++] & 1;
                ++validSubarrays;
            }
            ans += validSubarrays;
        }
        return ans;
    }

    public static void main(String[] args) {
        Count_Numbers_of_Nice_Subarrays solution = new Count_Numbers_of_Nice_Subarrays();

        int[] nums1 = {1,1,2,1,1};
        int k1 = 3;
        int ans1 = 2;

        int[] nums2 = {2,4,6};
        int k2 = 1;
        int ans2 = 0;

        int[] nums3 = {2,2,2,1,2,2,1,2,2,2};
        int k3 = 2;
        int ans3 = 16;
        long startTime = System.nanoTime();
        int test1 = solution.numberOfSubarrays(nums1, k1);
        int test2 = solution.numberOfSubarrays(nums2, k2);
        int test3 = solution.numberOfSubarrays(nums3, k3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}