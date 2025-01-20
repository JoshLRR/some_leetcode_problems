class Grumpy_Bookstore_Owner {
    
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int satisfied = 0;
        int n = customers.length;
        for (int idx = 0; idx < n; ++idx) {
            if (grumpy[idx] == 0) {
                satisfied += customers[idx];
            }
        }

        int windowStart = 0, windowMax = 0, windowCurrent = 0;

        for (int windowEnd = 0; windowEnd < n; ++windowEnd) {
            if (grumpy[windowEnd] == 1) {
                windowCurrent += customers[windowEnd];
            }

            if (windowEnd - windowStart + 1 >= minutes) {
                windowMax = Integer.max(windowMax, windowCurrent);
                if (grumpy[windowStart] == 1) {
                    windowCurrent -= customers[windowStart];
                }
                ++windowStart;
            }
        }

        return satisfied + windowMax;
    }

    /*
     * Do a dry-run through the customers array to see how many customers would be satisfied without using the technique
     * Then, using a sliding window of size 'minutes', we determine the number of customers that would be left unsatisfied by a grumpy store owner
     * Keep track of the max customers that could be satisfied instead by using the technique
     * Return the baseline + the number found through the sliding window technique
     */

    public static void main(String[] args) {
        Grumpy_Bookstore_Owner solution = new Grumpy_Bookstore_Owner();
        int[] customers1 = {1,0,1,2,1,1,7,5};
        int[] grumpy1 = {0,1,0,1,0,1,0,1};
        int minutes1 = 3;
        int ans1 = 16;

        int[] customers2 = {1};
        int[] grumpy2 = {0};
        int minutes2 = 1;
        int ans2 = 1;

        int[] customers3 = {4,10,10};
        int[] grumpy3 = {1,1,0};
        int minutes3 = 2;
        int ans3 = 24;
        long startTime = System.nanoTime();
        int test1 = solution.maxSatisfied(customers1, grumpy1, minutes1);
        int test2 = solution.maxSatisfied(customers2, grumpy2, minutes2);
        int test3 = solution.maxSatisfied(customers3, grumpy3, minutes3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}