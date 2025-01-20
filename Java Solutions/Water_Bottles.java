class Water_Bottles {
    
    public int numWaterBottles(int numBottles, int numExchange) {
        int maxBottles = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles > 0) {
            int tradedBottles = emptyBottles / numExchange;
            int emptyUntraded = emptyBottles % numExchange;
            maxBottles += tradedBottles;
            emptyBottles = tradedBottles + emptyUntraded;
            
            System.out.println("maxBottles: " + maxBottles + " emptyBottles: " + emptyBottles);
            if (emptyBottles < numExchange) break;
        }
        
        return maxBottles;
    }

    public static void main(String[] args) {
        Water_Bottles solution = new Water_Bottles();

        int numBottles1 = 9;
        int numExchange1 = 3;
        int ans1 = 13;

        int numBottles2 = 15;
        int numExchange2 = 4;
        int ans2 = 19;
        long startTime = System.nanoTime();
        int test1 = solution.numWaterBottles(numBottles1, numExchange1);
        int test2 = solution.numWaterBottles(numBottles2, numExchange2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}