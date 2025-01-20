import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;;

class Intersection_of_Two_Arrays_II {

    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> nums1FreqMap = new HashMap<>();
        HashMap<Integer, Integer> nums2FreqMap = new HashMap<>();
        List<Integer> ans = new ArrayList<>();        
        
        for (int num : nums1) {
            nums1FreqMap.put(num, nums1FreqMap.getOrDefault(num, 0) + 1);
        }
        for (int num : nums2) {
            nums2FreqMap.put(num, nums2FreqMap.getOrDefault(num, 0) + 1);
        }

        for (Integer key : nums1FreqMap.keySet()) {
            if (nums2FreqMap.getOrDefault(key, 0) != 0) {
                int freq = Integer.min(nums1FreqMap.get(key), nums2FreqMap.get(key));

                for (int idx = 0; idx < freq; ++idx) {
                    ans.add(key);
                }
            }
        }

        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
            // System.out.print(result[i] + ", ");
        }
        // System.out.println();
        
        return result;
    }

    /*
     * 
     * Memory usage can be improved by using a two-pointer approach and sorting both arrays
     *      Sort both arrays
     *      While loop for a single pointer in both arrays, while it's sitll in bounds
     *      If num at each pointer is equal, increment both and add the number to the ans list
     *      If one is greater, increment the corresponding pointer
     *      Time complexity however will be O(n logn)
     */

    public static void main(String[] args) {
        Intersection_of_Two_Arrays_II solution = new Intersection_of_Two_Arrays_II();

        int[] nums1 = {1,2,2,1};
        int[] nums2 = {2,2};
        int[] ans1 = {2,2};

        int[] nums3 = {4,9,5};
        int[] nums4 = {9,4,9,8,4};
        int[] ans2 = {4,9};

        long startTime = System.nanoTime();
        int[] test1 = solution.intersect(nums1, nums2);
        int[] test2 = solution.intersect(nums3, nums4);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}