class Count_Negative_Numbers_in_a_Sorted_Matrix {

    public int countNegatives(int[][] grid) {
        int negativeCount = 0;
        int n = grid.length;
        int m = grid[0].length;

        for (int idx = 0; idx < n; ++idx) {
            int left = 0;
            int right = m - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (grid[idx][mid] < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            negativeCount += m - left;
        }

        return negativeCount;
    }

    public static void main(String[] args) {
        Count_Negative_Numbers_in_a_Sorted_Matrix solution = new Count_Negative_Numbers_in_a_Sorted_Matrix();

        int[][] grid1 = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
        int ans1 = 8;

        int[][] grid2 = {{3,2}, {1,0}};
        int ans2 = 0;
        long startTime = System.nanoTime();
        int test1 = solution.countNegatives(grid1);
        int test2 = solution.countNegatives(grid2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}