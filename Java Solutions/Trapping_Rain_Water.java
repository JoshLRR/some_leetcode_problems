class Trapping_Rain_Water {

    public int trap(int[] height) {
        int waterTrapped = 0;
        int left = 0;
        int right = height.length - 1;
        int maxLeftHeight = height[left];
        int maxRightHeight = height[right];

        while (left < right) {
            if (maxLeftHeight < maxRightHeight) {
                ++left;
                maxLeftHeight = Integer.max(maxLeftHeight, height[left]);
                waterTrapped += maxLeftHeight - height[left];
            } else {
                --right;
                maxRightHeight = Integer.max(maxRightHeight, height[right]);
                waterTrapped += maxRightHeight - height[right];
            }
        }
        
        return waterTrapped;
    }

    public static void main(String[] args) {
        Trapping_Rain_Water solution = new Trapping_Rain_Water();

        int[] height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
        int ans1 = 6;
        
        int[] height2 = {4,2,0,3,2,5};
        int ans2 = 9;
        long startTime = System.nanoTime();
        int test1 = solution.trap(height1);
        int test2 = solution.trap(height2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}