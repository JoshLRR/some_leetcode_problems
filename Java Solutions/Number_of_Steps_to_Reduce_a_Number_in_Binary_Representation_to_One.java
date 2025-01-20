class Number_of_Steps_to_Reduce_a_Number_in_Binary_Representation_to_One {

    // public int numSteps(String s) {
    //     int steps = 0;

    //     StringBuilder sb = new StringBuilder(s);

    //     while (!sb.toString().equals("1")) {
    //         if (sb.charAt(sb.length() - 1) == '0') {
    //             sb.deleteCharAt(sb.length() - 1);
    //         } else {
    //             int i = sb.length() - 1;
    //             while (i >= 0 && sb.charAt(i) == '1') {
    //                 sb.setCharAt(i, '0');
    //                 --i;
    //             }
    //             if (i >= 0) {
    //                 sb.setCharAt(i, '1');
    //             } else {
    //                 sb.insert(0, '1');
    //             }
    //         }
    //         ++steps;
    //     }

    //     return steps;
    // }
    public int numSteps(String s) {
        int ans = 0;
        int carry = 0;

        for (int idx = s.length() - 1; idx > 0; --idx) {
            ++ans;
            if (s.charAt(idx) - '0' + carry == 1) {
                carry = 1;
                ++ans;
            }
        }

        return ans + carry;
    }

    /* 
     * Need to work with the binary as a string since it goes up to 500 bits, which will not fit into any data type as a number
     */

    public static void main(String[] args) {
        Number_of_Steps_to_Reduce_a_Number_in_Binary_Representation_to_One solution = new Number_of_Steps_to_Reduce_a_Number_in_Binary_Representation_to_One();

        String s1 = "1101";
        int ans1 = 6;
        String s2 = "1";
        int ans2 = 0;
        String s3 = "10";
        int ans3 = 1;
    
        long startTime = System.nanoTime();
        assert solution.numSteps(s1) == ans1 : "Test 1 failed";
        assert solution.numSteps(s2) == ans2 : "Test 2 failed";
        assert solution.numSteps(s3) == ans3 : "Test 3 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}