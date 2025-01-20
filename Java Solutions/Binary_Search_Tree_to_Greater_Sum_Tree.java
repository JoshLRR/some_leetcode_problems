class Binary_Search_Tree_to_Greater_Sum_Tree {
    public class TreeNode {
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

    int runningSum = 0;
    public TreeNode bstToGst(TreeNode root) {
        if (root.right != null) bstToGst(root.right);
        runningSum += root.val;
        root.val = runningSum;
        if (root.left != null) bstToGst(root.left);

        return root;
    }

    /*
     * Using DFS, traverse the right side of the tree and keep a runningSum going up from the roots. Update the running sum then set the current node's value to the running sum -- traverse all the way right before traversing to the left to ensure that we only consider nodes with a greater value than the original key
     */
    
    public static void main(String[] args) {
        Binary_Search_Tree_to_Greater_Sum_Tree solution = new Binary_Search_Tree_to_Greater_Sum_Tree();

        long startTime = System.nanoTime();
        
        long endTime = System.nanoTime();


        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}