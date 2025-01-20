class Single_Number_III {
    public int[] singleNumber(int[] nums) {
        int runningXOR = 0;
        int[] ans = new int[2];

        for (int num : nums) {
            runningXOR ^= num;
        }

        int rightmostBit = runningXOR ^ (-runningXOR);

        for (int num : nums) {
            if ((num & rightmostBit) != 0) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }

        return ans; 
    }

    public static void main(String[] args) {
        Single_Number_III solution = new Single_Number_III();

        int[] nums1 = {1,2,1,3,2,5};
        int[] ans1 = {3,5};

        int[] nums2 = {-1,0};
        int[] ans2 = {-1, 0};

        int[] nums3 = {0,1};
        int[] ans3 = {1,0}; 
        long startTime = System.nanoTime();
        assert solution.singleNumber(nums1) == ans1 : "Test 1 failed";
        assert solution.singleNumber(nums2) == ans2 : "Test 2 failed";
        assert solution.singleNumber(nums3) == ans3 : "Test 3 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}