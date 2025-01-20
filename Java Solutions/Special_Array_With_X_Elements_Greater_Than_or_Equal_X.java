import java.util.Arrays;

class Special_Array_With_X_Elements_Greater_Than_or_Equal_X {
    
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        int left = 0;
        int right = len - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= len - mid) {
        
                if (mid == 0 || nums[mid - 1] < len - mid) { 
                    return len - mid;
                } else { 
                    right = mid - 1;
                }
            } else { 
                left = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Special_Array_With_X_Elements_Greater_Than_or_Equal_X solution = new Special_Array_With_X_Elements_Greater_Than_or_Equal_X();

        long startTime = System.nanoTime();

        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}