import java.util.HashMap;

class Subarray_Sums_Divisible_by_K {

    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer,Integer> remainderMap = new HashMap<>();
        int ans = 0;
        int prefixSum = 0;
        remainderMap.put(0, 1);

        for (int idx = 0; idx < nums.length; ++idx) {
            prefixSum += nums[idx];
            int remainder = prefixSum % k;

            if (remainder < 0) remainder += k;

            if (remainderMap.containsKey(remainder)) {
                ans += remainderMap.get(remainder);
            }

            remainderMap.put(remainder, remainderMap.getOrDefault(remainder, 0) + 1);
        }

        return ans;
    }

    public static void main(String[] args) {
        Subarray_Sums_Divisible_by_K solution = new Subarray_Sums_Divisible_by_K();

        int[] nums1 = {4,5,0,-2,-3,1};
        int[] nums2 = {5};
        int k1 = 5;
        int k2 = 9;
        int ans1 = 7;
        int ans2 = 0;

        long startTime = System.nanoTime();
        int test1 = solution.subarraysDivByK(nums1, k1);
        int test2 = solution.subarraysDivByK(nums2, k2);
        long endTime = System.nanoTime();

        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}