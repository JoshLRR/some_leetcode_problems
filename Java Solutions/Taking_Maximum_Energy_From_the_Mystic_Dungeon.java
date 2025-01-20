class Taking_Maximum_Energy_From_the_Mystic_Dungeon {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length;
        int dp[] = new int[n];

        for (int idx = n - 1; idx >= 0; --idx) {
            dp[idx] = energy[idx] + ((idx + k < n) ? dp[idx + k] : 0);
        }

        int maxEnergy = Integer.MIN_VALUE;
        for (int num : dp) {
            maxEnergy = Math.max(maxEnergy, num);
        }
        
        System.out.println("Calculated energy: " + maxEnergy);
        return maxEnergy;
    }
    

    public static void main(String[] args) {
        Taking_Maximum_Energy_From_the_Mystic_Dungeon solution = new Taking_Maximum_Energy_From_the_Mystic_Dungeon();
        int[] energy1 = {5,2,-10,-5,1};
        int k1 = 3;
        int ans1 = 3;
        int[] energy2 = {-2,-3,-1};
        int k2 = 2;
        int ans2 = -1;
        long startTime = System.nanoTime();
        assert solution.maximumEnergy(energy1, k1) == ans1 : "Test 1 failed";
        assert solution.maximumEnergy(energy2, k2) == ans2 : "Test 2 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}