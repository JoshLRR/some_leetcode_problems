import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Palindrome_Partitioning {

    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        backtrack(s, 0, new ArrayList<>(), ans);
        return ans;
    }

    private void backtrack(String s, int start, List<String> currentList, List<List<String>> ans) {
        if (start == s.length()) {
            ans.add(new ArrayList<>(currentList));
            return;
        }

        for (int end = start + 1; end <= s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                currentList.add(s.substring(start, end));
                backtrack(s, end, currentList, ans);
                currentList.remove(currentList.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String s, int start, int end) {
        --end;
        while (start < end) {
            if (s.charAt(start++) != s.charAt(end--)) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Palindrome_Partitioning solution = new Palindrome_Partitioning();
        String s1 = "aab";
        List<List<String>> ans1 = List.of(
            List.of("a", "a", "b"),
            List.of("aa", "b")
        );
        String s2 = "a";
        List<List<String>> ans2 = List.of(
            List.of("a")
        );
        long startTime = System.nanoTime();
        assert solution.partition(s1) == ans1 : "Test 1 failed";
        assert solution.partition(s2) == ans2 : "Test 2 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}