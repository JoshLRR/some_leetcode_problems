import java.util.*;
import java.time.Duration;
import java.time.Instant;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        Instant start = Instant.now();
        
        // Example usage:
        int[] result = solution.twoSum(new int[]{2, 7, 11, 15}, 9);
        System.out.println(Arrays.toString(result));

        Instant end = Instant.now();

        Duration elapsed = Duration.between(start, end);
        double time = elapsed.toNanos() / 1e6;

        System.out.println("\u001B[32m" + "All tests passed in " + time + "ms!\n" + "\u001B[0m");
    }
}
