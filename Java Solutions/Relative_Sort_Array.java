import java.util.ArrayList;

class Relative_Sort_Array {
    
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int[] bucket = new int[1001];
        int[] ans = new int[n];

        for (int num : arr1) {
            ++bucket[num];
        }

        int ansPointer = 0;
        for (int num : arr2) {
            while (bucket[num] > 0) {
                ans[ansPointer] = num;
                ++ansPointer;
                --bucket[num];
            }
        }

        for (int idx = 0; idx < bucket.length; ++idx) {
            while (bucket[idx] > 0) {
                ans[ansPointer] = idx;
                ++ansPointer;
                --bucket[idx];
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Relative_Sort_Array solution = new Relative_Sort_Array();

        int[] arr1A = {2,3,1,3,2,4,6,7,9,2,19};
        int[] arr2A = {2,1,4,3,9,6};
        int[] ans1 = {2,2,2,1,4,3,3,9,6,7,19};

        int[] arr1B = {28,6,22,8,44,17};
        int[] arr2B = {22,28,8,6};
        int[] ans2 = {22,28,8,6,17,44};
        long startTime = System.nanoTime();
        int[] test1 = solution.relativeSortArray(arr1A, arr2A);
        int[] test2 = solution.relativeSortArray(arr1B, arr2B);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}