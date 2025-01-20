import java.util.ArrayList;

class Balance_a_Binary_Search_Tree {
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

    private ArrayList<Integer> numbers = new ArrayList<>();

    public TreeNode balanceBST(TreeNode root) {
        dfs(root);

        return createBST(0, numbers.size() - 1);
    }

    public void dfs(TreeNode node) {
        if (node == null) return;

        dfs(node.left);
        numbers.add(node.val);
        dfs(node.right);
    }

    public TreeNode createBST(int left, int right) {
        if (left > right) return null;

        int mid = left + (right - left) / 2;
        TreeNode node = new TreeNode(numbers.get(mid));

        node.left = createBST(left, mid - 1);
        node.right = createBST(mid + 1, right);

        return node;
    }

    public static void main(String[] args) {
        Balance_a_Binary_Search_Tree solution = new Balance_a_Binary_Search_Tree();

        long startTime = System.nanoTime();
        
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}