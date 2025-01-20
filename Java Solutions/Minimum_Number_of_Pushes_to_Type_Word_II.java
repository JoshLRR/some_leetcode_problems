import java.util.Arrays;
import java.util.Collections;

class Minimum_Number_of_Pushes_to_Type_Word_II {
    
    public int minimumPushes(String word) {
        int pushes = 0;
        int[] keyOccurences = new int[26];
        // Count key occurences using an int[26]
        for (char letter : word.toCharArray()) {
            ++keyOccurences[letter - 'a'];
        }

        // Sort key occurences in descending order
        Integer[] sortedFrequencies = new Integer[26]; // Create new Integer object array instead of primitive to allow the use of Collections.reverseOrder();
        for (int idx = 0; idx < 26; ++idx) {
            sortedFrequencies[idx] = keyOccurences[idx];
        }
        Arrays.sort(sortedFrequencies, Collections.reverseOrder());

        // Could probably just sort the first array and iterate through it backwards to prevent copying the array

        // Calculate total button presses
        for (int idx = 0; idx < 26; ++idx) {
            if (sortedFrequencies[idx] == 0) break;
            pushes += (idx / 8 + 1) * sortedFrequencies[idx];
        }

        return pushes;
    }

    public static void main(String[] args) {
        Minimum_Number_of_Pushes_to_Type_Word_II solution = new Minimum_Number_of_Pushes_to_Type_Word_II();

        String word1 = "abcde";
        int ans1 = 5;

        String word2 = "xyzxyzxyzxyz";
        int ans2 = 12;

        String word3 = "aabbccddeeffgghhiiiiii";
        int ans3 = 24;
        long startTime = System.nanoTime();
        int test1 = solution.minimumPushes(word1);
        int test2 = solution.minimumPushes(word2);
        int test3 = solution.minimumPushes(word3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}