class Count_Triplets_That_Can_Form_Two_Arrays_of_Equal_XOR {
    
    public int countTriplets(int[] arr) {
        int[] prefixes = new int[arr.length + 1];
        int ans = 0;

        for (int idx = 0; idx < arr.length; ++idx) {
            prefixes[idx + 1] = prefixes[idx] ^ arr[idx];
        }

        for (int idx = 0; idx < arr.length; ++idx) {
            for (int k = idx + 1; k < arr.length; ++k) {
                if (prefixes[idx] == prefixes[k + 1]) {
                    ans += k - idx;
                }
            }
        }

        return ans;
    }

    /*
     * a range is [i, j) (inclusive, exclusive)
     * b range is [j, k] (inclusive, inclusive)
     */ 

    public static void main(String[] args) {
        Count_Triplets_That_Can_Form_Two_Arrays_of_Equal_XOR solution = new Count_Triplets_That_Can_Form_Two_Arrays_of_Equal_XOR();
        
        int[] arr1 = {2,3,1,6,7};
        int ans1 = 4;

        int[] arr2 = {1,1,1,1,1};
        int ans2 = 10;
        long startTime = System.nanoTime();
        assert solution.countTriplets(arr1) == ans1 : "Test 1 failed";
        assert solution.countTriplets(arr2) == ans2 : "Test 2 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}