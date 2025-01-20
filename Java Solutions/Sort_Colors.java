class Sort_Colors {

    public void sortColors(int[] nums) {
        int red = 0, white = 0, blue = nums.length - 1;

        while (white <= blue) {
            if (nums[white] == 0) {
                int temp = nums[white];
                nums[white] = nums[red];
                nums[red] = temp;
                ++white;
                ++red;
            } else if (nums[white] == 1) {
                ++white;
            } else {
                int temp = nums[white];
                nums[white] = nums[blue];
                nums[blue] = temp;
                --blue;
            }
        }

        for (int num : nums) {
            System.out.print(num + ", ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Sort_Colors solution = new Sort_Colors();

        int[] nums1 = {2,0,2,1,1,0};
        int[] nums2 = {2,0,1};
        int[] ans1 = {0,0,1,1,2,2};
        int[] ans2 = {0,1,2};
        long startTime = System.nanoTime();
        solution.sortColors(nums1);
        solution.sortColors(nums2);
        long endTime = System.nanoTime();
        // assert nums1 == ans1 : "Test 1 failed, got " + nums1 + " instead of " + ans1;
        // assert nums2 == ans2 : "Test 2 failed, got " + nums2 + " instead of " + ans2;
        // assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}