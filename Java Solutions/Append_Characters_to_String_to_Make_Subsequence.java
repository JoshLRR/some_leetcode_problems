class Append_Characters_to_String_to_Make_Subsequence {

    public int appendCharacters(String s, String t) {
        int tIndex = 0;

        for (int sIdx = 0; sIdx < s.length(); ++sIdx) {
            if (t.charAt(tIndex) == s.charAt(sIdx)) {
                ++tIndex;
            } else {
                continue;
            }

            if (tIndex >= t.length()) {
                break;
            }
        }

        return t.length() - tIndex;
    }
    public static void main(String[] args) {
        Append_Characters_to_String_to_Make_Subsequence solution = new Append_Characters_to_String_to_Make_Subsequence();

        String s1 = "coaching";
        String t1 = "coding";
        int ans1 = 4;

        String s2 = "abcde";
        String t2 = "a";
        int ans2 = 0;

        String s3 = "z";
        String t3 = "abcde";
        int ans3 = 5;

        long startTime = System.nanoTime();
        int test1 = solution.appendCharacters(s1, t1);
        int test2 = solution.appendCharacters(s2, t2);
        int test3 = solution.appendCharacters(s3, t3);
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}