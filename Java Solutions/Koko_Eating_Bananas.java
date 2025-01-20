class Koko_Eating_Bananas {
    
    public int minEatingSpeed(int[] piles, int h) {
        int maxK = Integer.MIN_VALUE;

        for (int pile : piles) {
            if (pile > maxK) {
                maxK = pile;
            }
        }

        int left = 1;
        int right = maxK;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int timeToEat = 0;

            for (int pile : piles) {
                timeToEat += pile / mid + (pile % mid != 0 ? 1 : 0);
            }

            if (timeToEat > h) {
                left = mid + 1;
            } else {
                right = mid;
            }

        }
        return left;    
    }

    /*
     *  K -- min piles to max piles
     *  1   2   3   4   5   6   7   8   9   10  11
     *  L                   M                   R
     * 3 / 6 = 1, 6 / 6 = 1, 7 / 6 = 2, 11 / 6 = 2 --> 2 + 2 + 1 + 1 = 6
     * 6 <= 8, R = Mid - 1
     * 
     *  1   2   3   4   5
     *  L       M       R
     * 3 / 3 = 1, 6 / 3 = 2, 7 / 3 = 3, 11 / 3 = 4 --> 4 + 3 + 2 + 1 = 10
     * 10 > 8, L = Mid + 1
     * 
     *  4   5   
     *  L   R    
     * 3 / 4 = 1, 6 / 4 = 2, 7 / 4 = 2, 11 / 4 = 3 --> 3 + 2 + 2 + 1 = 7
     * 7 < 8, k = 4   
     */

    public static void main(String[] args) {
        Koko_Eating_Bananas solution = new Koko_Eating_Bananas();
        int[] piles1 = {3,6,7,11};
        int h1 = 8;
        int ans1 = 4;
        int[] piles2 = {30,11,23,4,20};
        int h2 = 5;
        int ans2 = 30;
        int[] piles3 = {30,11,23,4,20};
        int h3 = 6;
        int ans3 = 23;
        long startTime = System.nanoTime();
        assert solution.minEatingSpeed(piles1, h1) == ans1 : "Test 1 failed";
        assert solution.minEatingSpeed(piles2, h2) == ans2 : "Test 2 failed";
        assert solution.minEatingSpeed(piles3, h3) == ans3 : "Test 3 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}