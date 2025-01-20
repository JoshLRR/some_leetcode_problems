class Minimum_Numbers_of_K_Consecutive_Bit_Flips {

    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int flipped = 0;
        int[] isFlipped = new int[n];
        int numFlips = 0;

        for (int idx = 0; idx < n; ++idx) {
            if (idx >= k) {
                flipped ^= isFlipped[idx - k];
            }

            if (flipped == nums[idx]) {
                if (idx + k > n) return - 1;
                flipped ^= 1;
                isFlipped[idx] = 1;
                ++numFlips;
            }
        }

        return numFlips;
    }

    public static void main(String[] args) {
        Minimum_Numbers_of_K_Consecutive_Bit_Flips solution = new Minimum_Numbers_of_K_Consecutive_Bit_Flips();

        int[] nums1 = {0,1,0};
        int k1 = 1;
        int ans1 = 2;

        int[] nums2 = {1,1,0};
        int k2 = 2;
        int ans2 = -1;

        int[] nums3 = {0,0,0,1,0,1,1,0};
        int k3 = 3;
        int ans3 = 3;

        long startTime = System.nanoTime();
        int test1 = solution.minKBitFlips(nums1, k1);
        int test2 = solution.minKBitFlips(nums2, k2);
        int test3 = solution.minKBitFlips(nums3, k3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}