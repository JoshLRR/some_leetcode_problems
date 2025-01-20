class Basic_Calculator {

    public int calculate(String s) {
        
    }

    /*
     * Don't forget about multi-digit numbers 
     * 
     * 
     */

    public static void main(String[] args) {
        Basic_Calculator solution = new Basic_Calculator();

        String s1 = "1 + 1";
        int ans1 = 2;

        String s2 = " 2-1 + 2 ";
        int ans2 = 3;

        String s3 = "(1+(4+5+2)-3)+(6+8)";
        int ans3 = 23;

        long startTime = System.nanoTime();
        int test1 = solution.calculate(s1);
        int test2 = solution.calculate(s2);
        int test3 = solution.calculate(s3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}