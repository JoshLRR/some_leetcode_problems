class Average_Waiting_Time {

    public double averageWaitingTime(int[][] customers) {
        int availableAt = 0;
        double totalWait = 0;

        for (int[] customer : customers) {
            int arrival = customer[0];
            int cookTime = customer[1];

            availableAt = Math.max(availableAt, arrival) + cookTime;
            totalWait += availableAt - arrival;
        }

        return totalWait / customers.length;
    }

    public static void main(String[] args) {
        Average_Waiting_Time solution = new Average_Waiting_Time();

        int[][] customers1 = {{1,2}, {2,5}, {4,3}};
        double ans1 = 5.00000;

        int[][] customers2 = {{5,2}, {5,4}, {10,3}, {20,1}};
        double ans2 = 3.25000;

        long startTime = System.nanoTime();
        double test1 = solution.averageWaitingTime(customers1);
        double test2 = solution.averageWaitingTime(customers2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}