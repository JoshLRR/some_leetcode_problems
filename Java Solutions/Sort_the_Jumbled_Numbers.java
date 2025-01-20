import java.util.Comparator;
import java.util.Arrays;
import java.util.Stack;

class Sort_the_Jumbled_Numbers {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        int[][] shuffledNumAndIndex = new int[n][2];
        Stack<Integer> reverseDigitStack = new Stack<>();

        // Convert all nums and store with index of original num in nums
        int[] copy = nums;

        for (int idx = 0; idx < n; ++idx) {
            int newNum = 0;
            for (int num : copy) {
                newNum = 0;

                while (num > 0) {
                    int currDigit = num % 10;
                    num /= 10;
                    // newNum += mapping[currDigit];
                    // newNum *= 10;
                    reverseDigitStack.push(currDigit);
                }
                
                while (!reverseDigitStack.isEmpty()) {
                    newNum += reverseDigitStack.pop();
                    newNum *= 10;
                }
                System.out.println(newNum);
                shuffledNumAndIndex[idx][0] = newNum; // Need to reverse this num
                shuffledNumAndIndex[idx][1] = idx;
            }
        }

        // Sort the converted nums
        Arrays.sort(shuffledNumAndIndex, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });

        // for (int pair[] : shuffledNumAndIndex) {
        //     System.out.print(pair[0] + ", " + pair[1]);
        //     System.out.println();
        // }
    
        // Loop through the sorted converted nums, using the indices, get the original nums from nums and insert into an answer array --> just insert vals into copy
        for (int idx = 0; idx < n; ++idx) {
            copy[idx] = nums[shuffledNumAndIndex[idx][1]];
        }

        return copy;
    }

    public static void main(String[] args) {
        Sort_the_Jumbled_Numbers solution = new Sort_the_Jumbled_Numbers();

        int[] mapping1 = {8,9,4,0,2,1,3,5,7,6};
        int[] nums1 = {991, 338, 38};
        int[] ans1 = {338, 38, 991};

        int[] mapping2 = {0,1,2,3,4,5,6,7,8,9};
        int[] nums2 = {789, 456, 123};
        int[] ans2 = {123,456,789};

        long startTime = System.nanoTime();
        int[] test1 = solution.sortJumbled(mapping1, nums1);
        int[] test2 = solution.sortJumbled(mapping2, nums2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}