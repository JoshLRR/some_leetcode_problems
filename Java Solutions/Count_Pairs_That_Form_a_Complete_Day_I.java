import java.util.HashMap;

class Count_Pairs_That_Form_a_Complete_Day_I {
    
    // public int countCompleteDayPairs(int[] hours) {
    //     if (hours.length == 1) return 0;
    //     int dayPairs = 0;
        
    //     for (int idx = 0; idx < hours.length - 1; ++idx) {
    //         for (int jdx = idx + 1; jdx < hours.length; ++jdx) {
    //             if ((hours[idx] + hours[jdx]) % 24 == 0) {
    //                 ++dayPairs;
    //             }
    //         }
    //     }

    //     return dayPairs;
    // }
    public int countCompleteDayPairs(int[] hours) {
        HashMap<Integer, Integer> remainderCount = new HashMap<>();
        int count = 0;
        
        for (int hour : hours) {
            int remainder = hour % 24;
            if (remainder == 0) {
                count += remainderCount.getOrDefault(0, 0);
            } else {
                count += remainderCount.getOrDefault(24 - remainder, 0);
            }
            remainderCount.put(remainder, remainderCount.getOrDefault(remainder, 0) + 1);
        }

        return count;
    }

    public static void main(String[] args) {
        Count_Pairs_That_Form_a_Complete_Day_I solution = new Count_Pairs_That_Form_a_Complete_Day_I();

        int[] hours1 = {12,12,30,24,24};
        int ans1 = 2;

        int[] hours2 = {72,48,24,3};
        int ans2 = 3;

        int[] hours3 = {24,24};
        int ans3 = 1;

        int[] hours4 = {12};
        int ans4 = 0;
        long startTime = System.nanoTime();
        int test1 = solution.countCompleteDayPairs(hours1);
        int test2 = solution.countCompleteDayPairs(hours2);
        int test3 = solution.countCompleteDayPairs(hours3);
        int test4 = solution.countCompleteDayPairs(hours4);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;
        assert test4 == ans4 : "Test 4 failed, got " + test4 + " instead of " + ans4;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}