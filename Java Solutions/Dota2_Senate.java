
import java.util.Queue;
import java.util.LinkedList;
import java.util.PriorityQueue;

class Dota2_Senate {

    public String predictPartyVictory(String senate) {
        Queue<Integer> radiantQueue = new LinkedList<>();
        Queue<Integer> direQueue = new LinkedList<>();

        for (int idx = 0; idx < senate.length(); ++idx) {
            if (senate.charAt(idx) == 'R') {
                radiantQueue.add(idx);
            } else {
                direQueue.add(idx);
            }
        }

        while (!radiantQueue.isEmpty() && !direQueue.isEmpty()) {
            int radiantIndex = radiantQueue.remove();
            int direIndex = direQueue.remove();

            if (radiantIndex < direIndex) {
                radiantQueue.add(radiantIndex + senate.length());
            } else {
                direQueue.add(direIndex + senate.length());
            }
        }

        return radiantQueue.isEmpty() ? "Dire" : "Radiant";
    }
    public static void main(String[] args) {
        Dota2_Senate solution = new Dota2_Senate();

        String senate1 = "RD";
        String ans1 = "Radiant";
        String senate2 = "RDD";
        String ans2 = "Dire";
        long startTime = System.nanoTime();
        assert solution.predictPartyVictory(senate1) == ans1 : "Test 1 failed";
        assert solution.predictPartyVictory(senate2) == ans2 : "Test 2 failed";
        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}