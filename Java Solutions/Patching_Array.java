class Patching_Array {
    
    public int minPatches(int[] nums, int n) {
        long miss = 1;
        int added = 0;
        int i = 0;

        while (miss <= n) {
            if (i < nums.length && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                added++;
            }
        }
        return added;
    }

    public static void main(String[] args) {
        Patching_Array solution = new Patching_Array();

        int[] nums1 = {1,3};
        int n1 = 6;
        int ans1 = 1;

        int[] nums2 = {1,5,10};
        int n2 = 20;
        int ans2 = 2;
        
        int[] nums3 = {1,2,2};
        int n3 = 5;
        int ans3 = 0;

        long startTime = System.nanoTime();
        int test1 = solution.minPatches(nums1, n1);
        int test2 = solution.minPatches(nums2, n2);
        int test3 = solution.minPatches(nums3, n3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}