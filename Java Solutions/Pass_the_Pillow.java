class Pass_the_Pillow {

    public int passThePillow(int n, int time) {
        int rounds = time / (n - 1);

        if (rounds % 2 == 0) {
            return 1 + time % (n - 1);
        } else {
            return n - time % (n - 1);
        }
    }

    public static void main(String[] args) {
        Pass_the_Pillow solution = new Pass_the_Pillow();

        int n1 = 4;
        int time1 = 5;
        int ans1 = 2;

        int n2 = 3;
        int time2 = 2;
        int ans2 = 3;

        int n3 = 4;
        int time3 = 5;
        int ans3 = 2;
        long startTime = System.nanoTime();
        int test1 = solution.passThePillow(ans1, time1);
        int test2 = solution.passThePillow(ans2, time2);
        int test3 = solution.passThePillow(ans3, time3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}