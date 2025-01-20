class Container_With_Most_Water {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int left = 0, right = height.length - 1;

        while (left < right) {
            // int currArea = Math.min(height[left], height[right]) * (right - left);
            int currArea = 0;
            if (height[left] > height[right]) {
                currArea = height[right] * (right - left);
                --right;
            } else {
                currArea = height[left] * (right - left);
                ++left;
            }
            maxArea = Math.max(currArea, maxArea);
        }

        return maxArea;
    }

    public static void main(String[] args) {
        Container_With_Most_Water solution = new Container_With_Most_Water();

        int[] height1 = {1,8,6,2,5,4,8,3,7};
        int ans1 = 49;

        int[] height2 = {1,1};
        int ans2 = 1;
        long startTime = System.nanoTime();
        int test1 = solution.maxArea(height1);
        int test2 = solution.maxArea(height2);
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}