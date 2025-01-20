class Path_with_Maximum_Gold {
    private static final int[][] directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    private int dfs(int currRow, int currCol, int[][] grid, int n, int m) {
        if (currRow < 0 || currRow >= n || currCol < 0 || currCol >= m || grid[currRow][currCol] == 0) return 0;

        int gold = grid[currRow][currCol];
        grid[currRow][currCol] = 0;

        int maxGold = 0;
        for (int[] direction : directions) {
            int newRow = currRow + direction[0];
            int newCol = currCol + direction[1];
            maxGold = Math.max(maxGold, dfs(newRow, newCol, grid, n, m));
        }
        grid[currRow][currCol] = gold;

        return maxGold + gold;
    }

    public int getMaximumGold(int[][] grid) {
        int maxGold = Integer.MIN_VALUE;
        int n = grid.length;
        int m = grid[0].length;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                maxGold = Math.max(maxGold, dfs(row, col, grid, n, m));
            }
        }
        
        // System.out.println(maxGold);
        return maxGold;
    }

    public static void main(String[] args) {
        // Solution solution = new Solution();
        Path_with_Maximum_Gold solution = new Path_with_Maximum_Gold();
        int[][] grid1 = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
        int ans1 = 24;
        int[][] grid2 = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};
        int ans2 = 28;

        long startTime = System.nanoTime();
        assert solution.getMaximumGold(grid1) == ans1 : "Test 1 failed";
        assert solution.getMaximumGold(grid2) == ans2 : "Test 2 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}