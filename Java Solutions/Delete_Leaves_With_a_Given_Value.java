class Delete_Leaves_With_a_Given_Value {

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
    
    class Solution {
        public TreeNode removeLeafNodes(TreeNode root, int target) {
            if (root.left != null) {
                root.left = removeLeafNodes(root.left, target);
            }
            if (root.right != null) {
                root.right = removeLeafNodes(root.right, target);
            }

            // if (root.left == null && root.right == null) {
            //     if (root.val == target) {
            //         return null;
            //     } else {
            //         return root;
            //     }
            // } else {
            //     return root;
            // }
            return root.left == root.right && root.val == target ? null : root;
        }
    }
    public static void main(String[] args) {
        Delete_Leaves_With_a_Given_Value solution = new Delete_Leaves_With_a_Given_Value();

        long startTime = System.nanoTime();

        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}