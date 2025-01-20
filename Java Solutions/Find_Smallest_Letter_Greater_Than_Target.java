class Find_Smallest_Letter_Greater_Than_Target {

    public char nextGreatestLetter(char[] letters, char target) {
        int left = 0;
        int right = letters.length - 1;

        if (letters[right] - 'a' <= target - 'a') return letters[0];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return letters[left];
    }

    public static void main(String[] args) {
        Find_Smallest_Letter_Greater_Than_Target solution = new Find_Smallest_Letter_Greater_Than_Target();

        char[] letters1 = {'c', 'f', 'j'};
        char target1 = 'a';
        char ans1 = 'c';

        char[] letters2 = {'c', 'f', 'j'};
        char target2 = 'c';
        char ans2 = 'f';

        char[] letters3 = {'x', 'x', 'y', 'y'};
        char target3 = 'z';
        char ans3 = 'x';
        long startTime = System.nanoTime();
        char test1 = solution.nextGreatestLetter(letters1, target1);
        char test2 = solution.nextGreatestLetter(letters2, target2);
        char test3 = solution.nextGreatestLetter(letters3, target3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}