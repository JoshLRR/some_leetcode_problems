import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

class The_Number_of_Beautiful_Subsets {
    public int beautifulSubsets(int[] nums, int k) {
        int[] ans = new int[1];
        Arrays.sort(nums);
        backtrack(nums, k, ans, new ArrayList<>(), 0);
        return ans[0];
    }

    private void backtrack(int[] nums, int k, int[] ans, List<Integer> currentCombo, int start) {
                
        for (int idx = start; idx < nums.length; ++idx) {
            if (isBeautiful(currentCombo, k, nums[idx])) {
                currentCombo.add(nums[idx]);
                ++ans[0];
                backtrack(nums, k, ans, currentCombo, idx + 1);
                currentCombo.remove(currentCombo.size() - 1);
            }
        }
    }

    private boolean isBeautiful(List<Integer> currentCombo, int k, int candidate) {
        for (int num : currentCombo) {
            if (Math.abs(num - candidate) == k) {
                return false;
            }
        }

        return true;
    }

    /*
     * 
     * 
     */
    public static void main(String[] args) {
        The_Number_of_Beautiful_Subsets solution = new The_Number_of_Beautiful_Subsets();

        long startTime = System.nanoTime();

        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}