import java.util.HashMap;

class Longest_Palindrome {
    public int longestPalindrome(String s) {
        int oddCount = 0;
        HashMap<Character, Integer> freqMap = new HashMap<>();

        for (char ch : s.toCharArray()) {
            freqMap.put(ch, freqMap.getOrDefault(ch, 0) + 1);
            if (freqMap.get(ch) % 2 == 1) {
                ++oddCount;
            } else {
                --oddCount;
            }
        }

        if (oddCount > 1) {
            return s.length() - oddCount + 1;
        }
        
        return s.length();
    }

    public static void main(String[] args) {
        Longest_Palindrome solution = new Longest_Palindrome();
        
        String s1 = "abccccdd";
        int ans1 = 7;

        String s2 = "a";
        int ans2 = 1;

        long startTime = System.nanoTime();
        int test1 = solution.longestPalindrome(s1);
        int test2 = solution.longestPalindrome(s2);
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}