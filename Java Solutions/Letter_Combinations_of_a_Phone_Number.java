import java.util.ArrayList;
import java.util.List;

class Letter_Combinations_of_a_Phone_Number {
    List<String> ans = new ArrayList<>();
    // (1) Define the mapping from digits to their corresponding letters
    String[] digitToLetters = { "",    // 0
                                "",    // 1
                                "abc", // 2
                                "def", // 3
                                "ghi", // 4
                                "jkl", // 5
                                "mno", // 6
                                "pqrs", // 7
                                "tuv", // 8
                                "wxyz"}; // 9

    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return ans; // Handle empty input edge case
        generateCombo(0, digits, new StringBuilder());

        // for (String thing : ans) {
        //     System.out.print(thing + ", ");
        // }
        // System.out.println();
        return ans;
    }

    private void generateCombo(int start, String digits, StringBuilder currCombo) {
        // (2) Adjust the base case to add to answer list only when the current combination's length matches the digits length
        if (start == digits.length()) {
            ans.add(currCombo.toString());
            return;
        }
        
        String letters = digitToLetters[digits.charAt(start) - '0']; // Map digit to letters
        for (int i = 0; i < letters.length(); i++) { // Iterate over all possible letters for the current digit
            currCombo.append(letters.charAt(i));
            generateCombo(start + 1, digits, currCombo); // Recursive call to handle the next digit
            currCombo.deleteCharAt(currCombo.length() - 1); // Backtrack
        }
    }



    public static void main(String[] args) {
        Letter_Combinations_of_a_Phone_Number solution = new Letter_Combinations_of_a_Phone_Number();

        String digits1 = "23";
        List<String> ans1 = List.of(
            "ad","ae","af","bd","be","bf","cd","ce","cf"
        );

        String digits2 = "";
        List<String> ans2 = List.of();

        String digits3 = "2";
        List<String> ans3 = List.of(
            "a", "b", "c"
        );
        long startTime = System.nanoTime();
        assert solution.letterCombinations(digits1) == ans1 : "Test 1 Failed";
        assert solution.letterCombinations(digits2) == ans2 : "Test 2 Failed";
        assert solution.letterCombinations(digits3) == ans3 : "Test 3 Failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}