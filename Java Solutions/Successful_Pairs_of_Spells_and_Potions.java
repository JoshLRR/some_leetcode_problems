import java.util.Arrays;

class Successful_Pairs_of_Spells_and_Potions {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int[] ans = new int[n];
        Arrays.sort(potions);
        int m = potions.length;
        
        int idx = 0;
        for (int spell : spells) {
            int left = 0;
            int right = m - 1;
            long target = (success + spell - 1) / spell;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (potions[mid] >= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans[idx] = m - left;
            ++idx;
        }

        for (int num : ans) {
            System.out.print(num + ", ");
        }
        System.out.println();
        
        return ans;
    }

    // Sort potions
    // success / spells[i] = minimum potion strength for a good combo
    // Use binary search to find index of first viable potion
    // potions length - index = number of viable potions, push to ans
    public static void main(String[] args) {
        Successful_Pairs_of_Spells_and_Potions solution = new Successful_Pairs_of_Spells_and_Potions();
        int[] spells1 = {5,1,3};
        int[] potions1 = {1,2,3,4,5};
        long success1 = 7;
        int[] ans1 = {4,0,3};
        int[] spells2 = {3,1,2};
        int[] potions2 = {8,5,8};
        long success2 = 16;
        int[] ans2 = {2,0,2};
        long startTime = System.nanoTime();
        assert solution.successfulPairs(spells1, potions1, success1) == ans1 : "test 1 failed";
        assert solution.successfulPairs(spells2, potions2, success2) == ans2 : "test 2 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}