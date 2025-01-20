import java.util.Arrays;

class Hand_of_Straights {

    public boolean isNStraightHand(int[] hand, int groupSize) {
        int n = hand.length;
        if (n % groupSize != 0) {
            return false;
        }
    
        Arrays.sort(hand);
    
        for (int i = 0; i < n; ++i) {
            if (hand[i] == -1) {
                continue; // Skip already used cards
            }
    
            int sequenceSize = 1;
            int lastUsed = hand[i];
            hand[i] = -1; // Mark this card as used
    
            for (int j = i + 1; j < n && sequenceSize < groupSize; ++j) {
                if (hand[j] != -1 && hand[j] == lastUsed + 1) {
                    lastUsed = hand[j];
                    hand[j] = -1; // Mark this card as used
                    sequenceSize++;
                }
            }
    
            if (sequenceSize != groupSize) {
                return false; // If a group cannot be formed, return false
            }
        }
    
        return true;
    }


    public static void main(String[] args) {
        Hand_of_Straights solution = new Hand_of_Straights();

        int[] hand1 = {1,2,3,6,2,3,4,7,8};
        int groupSize1 = 3;
        boolean ans1 = true;

        int[] hand2 = {1,2,3,4,5};
        int groupSize2 = 4;
        boolean ans2 = false;

        int[] hand3 = {8,10,12};
        int groupSize3 = 3;
        boolean ans3 = false;

        long startTime = System.nanoTime();
        long endTime = System.nanoTime();
        boolean test1 = solution.isNStraightHand(hand1, groupSize1);
        boolean test2 = solution.isNStraightHand(hand2, groupSize2);
        boolean test3 = solution.isNStraightHand(hand3, groupSize3);
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}