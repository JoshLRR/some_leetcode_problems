import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

class Subsets {
    public void generateSet(List<List<Integer>> subsets, List<Integer> currCombo, int start, int[] nums) {
        subsets.add(new ArrayList<>(currCombo));

        for (int idx = start; idx < nums.length; ++idx) {
            currCombo.add(nums[idx]);
            generateSet(subsets, currCombo, idx + 1, nums);
            currCombo.remove(currCombo.size() - 1);
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> subsets = new ArrayList<>();
        List<Integer> currCombo = new ArrayList<>();
        generateSet(subsets, currCombo, 0, nums);

        for (List<Integer> set : subsets) {
            System.out.print("{");
            for (Integer num : set) {
                System.out.print(num + ", ");
            }
            System.out.println("}");
        }
        return subsets;
    }
    
    public static void main(String[] args) {
        Subsets solution = new Subsets();
        int[] nums1 = {1, 2, 3};
        List<List<Integer>> ans1 = Arrays.asList(
            Arrays.asList(),
            Arrays.asList(1),
            Arrays.asList(2),
            Arrays.asList(1, 2),
            Arrays.asList(3),
            Arrays.asList(1, 3),
            Arrays.asList(2, 3),
            Arrays.asList(1, 2, 3)
        );
        
        int[] nums2 = {0};
        List<List<Integer>> ans2 = Arrays.asList(
            Arrays.asList(),
            Arrays.asList(0)
        );
        
        long startTime = System.nanoTime();
        assert solution.subsets(nums1).equals(ans1) : "Test case 1 failed";
        assert solution.subsets(nums2).equals(ans2) : "Test case 2 failed";
        long endTime = System.nanoTime();
        
        double time = (endTime - startTime) / 1e6;
        System.out.println("\033[32m" + "All tests passed in " + time + "ms!\n" + "\033[0m");
    }
}
