import java.util.HashMap;

class Find_Center_of_Star_Graph {

    public int findCenter(int[][] edges) {
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        
        for (int[] edge : edges) {
            for (int num : edge) {
                freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);

                if (freqMap.get(num) > 1) {
                    return num;
                }
            }
        }
        
        return -1;
    }

    public static void main(String[] args) {
        Find_Center_of_Star_Graph solution = new Find_Center_of_Star_Graph();

        int[][] edges1 = {{1,2}, {2,3}, {4,2}};
        int ans1 = 2;

        int[][] edges2 = {{1,2,}, {5,1}, {1,3}, {1,4}};
        int ans2 = 1;
        long startTime = System.nanoTime();
        int test1 = solution.findCenter(edges1);
        int test2 = solution.findCenter(edges2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}