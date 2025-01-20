import java.util.HashMap;
import java.util.Map;

class Maximum_Score_Words_Formed_by_Letters {
    int ans = 0;

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        // Initialize the frequency array for letters
        int[] letterFrequency = new int[26];
        for (char letter : letters) {
            letterFrequency[letter - 'a']++;
        }

        findScores(0, words, letterFrequency, score, 0);
        return ans;
    }

    private void findScores(int start, String[] words, int[] letterFrequency, int[] score, int runningScore) {
        // Base Case
        if (start >= words.length) {
            ans = Math.max(ans, runningScore);
            return;
        }

        // Recursive Case: Exclude the current word
        findScores(start + 1, words, letterFrequency, score, runningScore);

        // Check if we can include the current word
        String word = words[start];
        boolean canFormWord = true;
        int wordScore = 0;

        // Decrement letter frequencies and calculate word score
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (letterFrequency[ch - 'a'] <= 0) {
                canFormWord = false;
            }
            letterFrequency[ch - 'a']--;
            wordScore += score[ch - 'a'];
        }

        // Recursive Case: Include the current word if valid
        if (canFormWord) {
            findScores(start + 1, words, letterFrequency, score, runningScore + wordScore);
        }

        // Backtrack: Restore letter frequencies
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            letterFrequency[ch - 'a']++;
        }
    }

    public static void main(String[] args) {
        Maximum_Score_Words_Formed_by_Letters solution = new Maximum_Score_Words_Formed_by_Letters();
        String[] words1 = {"dog","cat","dad","good"};
        char[] letters1 = {'a','a','c','d','d','d','g','o','o'};
        int[] score1 = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
        int ans1 = 23;

        String[] words2 = {"xxxz","ax","bx","cx"};
        char[] letters2 = {'z','a','b','c','x','x','x'};
        int[] score2 = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
        int ans2 = 27;
        long startTime = System.nanoTime();
        assert(solution.maxScoreWords(words1, letters1, score1)) == ans1 : "Test 1 failed";
        assert(solution.maxScoreWords(words2, letters2, score2)) == ans2 : "Test 2 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}