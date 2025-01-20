class Find_the_Minimum_Area_to_Cover_All_Ones_I {

    public int minimumArea(int[][] grid) {
        int leftSide = Integer.MAX_VALUE;
        int rightSide = Integer.MIN_VALUE;
        int topSide = Integer.MAX_VALUE;
        int bottomSide = Integer.MIN_VALUE;

        for (int row = 0; row < grid.length; ++row) {
            for (int col = 0; col < grid[0].length; ++col) {
                if (grid[row][col] == 1) {
                    leftSide = Integer.min(leftSide, col);
                    topSide = Integer.min(topSide, row);
                    rightSide = Integer.max(rightSide, col);
                    bottomSide = Integer.max(bottomSide, row);
                }
            }
        }

        // System.out.println("Left Side: " + leftSide + " Top Side: "+ topSide + " Right Side: " + rightSide + " Bottom Side: " + bottomSide);

        return (rightSide - leftSide + 1) * (bottomSide - topSide + 1);
    }

    public static void main(String[] args) {
        Find_the_Minimum_Area_to_Cover_All_Ones_I solution = new Find_the_Minimum_Area_to_Cover_All_Ones_I();
        
        int[][] grid1 = {{0,1,0}, {1,0,1}};
        int ans1 = 6;

        int[][] grid2 = {{1,0}, {0,0}};
        int ans2 = 1;

        int[][] grid3 = {{0}, {1}};
        int ans3 = 1;
        long startTime = System.nanoTime();
        int test1 = solution.minimumArea(grid1);
        int test2 = solution.minimumArea(grid2);
        int test3    = solution.minimumArea(grid3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}