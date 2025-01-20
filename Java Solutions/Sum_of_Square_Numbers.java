class Sum_of_Square_Numbers {

    public boolean judgeSquareSum(int c) {
        long left = 0;
        long right = (long) Math.sqrt(c);
        
        while (left <= right) {
            long squareSum = left * left + right * right;

            if (squareSum > c) {
                --right;
            } else if (squareSum < c) {
                ++left;
            } else {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Sum_of_Square_Numbers solution = new Sum_of_Square_Numbers();
        int c1 = 5;
        boolean ans1 = true;

        int c2 = 3;
        boolean ans2 = false;

        int c3 = 4;
        boolean ans3 = true;

        int c4 = 1;
        boolean ans4 = true;

        int c5 = 0;
        boolean ans5 = true;

        int c6 = 1000000;
        boolean ans6 = true;
        long startTime = System.nanoTime();
        boolean test1 = solution.judgeSquareSum(c1);
        boolean test2 = solution.judgeSquareSum(c2);
        boolean test3 = solution.judgeSquareSum(c3);
        boolean test4 = solution.judgeSquareSum(c4);
        boolean test5 = solution.judgeSquareSum(c5);
        boolean test6 = solution.judgeSquareSum(c6);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;
        assert test4 == ans4 : "Test 4 failed, got " + test4 + " instead of " + ans4;
        assert test5 == ans5 : "Test 5 failed, got " + test5 + " instead of " + ans5;
        assert test6 == ans6 : "Test 6 failed, got " + test6 + " instead of " + ans6;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}