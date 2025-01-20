class Three_Consecutive_Odds {
    
    public boolean threeConsecutiveOdds(int[] arr) {
        int numSeen = 0;
        
        for (int num : arr) {
            if (num % 2 == 1) { 
                ++numSeen;
                if (numSeen == 3) {
                    return true;
                }
            } else {
                numSeen = 0;
            }
        }
        
        return false;
    }

    public static void main(String[] args) {
        Three_Consecutive_Odds solution = new Three_Consecutive_Odds();

        int[] arr1 = {2,6,4,1};
        boolean ans1 = false;

        int[] arr2 = {1,2,34,3,4,5,7,23,12};
        boolean ans2 = true;

        int[] arr3 = {1,1,1};
        boolean ans3 = true;

        int[] arr4 = {1,2,1,1};
        boolean ans4 = false;

        int[] arr5 = {102,780,919,897,901};
        boolean ans5 = true;
        long startTime = System.nanoTime();
        boolean test1 = solution.threeConsecutiveOdds(arr1);
        boolean test2 = solution.threeConsecutiveOdds(arr2);
        boolean test3 = solution.threeConsecutiveOdds(arr3);
        boolean test4 = solution.threeConsecutiveOdds(arr4);
        boolean test5 = solution.threeConsecutiveOdds(arr5);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;
        assert test4 == ans4 : "Test 4 failed, got " + test4 + " instead of " + ans4;
        assert test5 == ans5 : "Test 5 failed, got " + test5 + " instead of " + ans5;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}