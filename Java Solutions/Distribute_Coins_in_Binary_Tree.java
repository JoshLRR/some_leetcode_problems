class Distribute_Coins_in_Binary_Tree {
        
     
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
     
    int coinMoves = 0;
    public int dfs(TreeNode node) {
        if (node == null) return 0;

        int left = dfs(node.left);
        int right = dfs(node.right);
        coinMoves += Math.abs(left) + Math.abs(right);

        return node.val + left + right - 1;
    }

    public int distributeCoins(TreeNode root) {
        dfs(root);
        return coinMoves;
    }
    public static void main(String[] args) {
        Distribute_Coins_in_Binary_Tree solution = new Distribute_Coins_in_Binary_Tree();

        TreeNode tree1 = new TreeNode(3, new TreeNode(0), new TreeNode(0));
        TreeNode tree2 = new TreeNode(0, new TreeNode(3), new TreeNode(0));
        int ans1 = 2;
        int ans2 = 3;
        long startTime = System.nanoTime();
        assert solution.distributeCoins(tree1) == ans1 : "Test 1 failed";
        assert solution.distributeCoins(tree2) == ans2 : "Test 2 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}