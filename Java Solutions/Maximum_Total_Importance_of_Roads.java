import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.Map;
import java.util.Comparator;
import java.util.Arrays;

class Maximum_Total_Importance_of_Roads {

    // class ArrayComparator implements Comparator<int[]> {
    //     @Override
    //     public int compare(int[] a1, int[] a2) {
    //         return Integer.compare(a2[0], a1[0]);
    //     }
    // }

    // public long maximumImportance(int n, int[][] roads) {
    //     long totalImportance = 0;
    //     HashMap<Integer, Integer> freqMap = new HashMap<>();
    //     HashMap<Integer, Integer> pointMap = new HashMap<>();
    //     PriorityQueue<int[]> maxHeap = new PriorityQueue<>(new ArrayComparator());

    //     for (int[] road : roads) {
    //         freqMap.put(road[0], freqMap.getOrDefault(road[0], 0) + 1);
    //         freqMap.put(road[1], freqMap.getOrDefault(road[1], 0) + 1);
    //     }

    //     for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {
    //         // System.out.println(entry.getKey() + " : " + entry.getValue());
    //         maxHeap.add(new int[]{entry.getValue(), entry.getKey()});
    //     }

    //     while (!maxHeap.isEmpty() && n > 0) {
    //         int[] curr = maxHeap.remove();
    //         pointMap.put(curr[1], n);
    //         --n;
    //     }

    //     for (int[] road : roads) {
    //         totalImportance += pointMap.get(road[0]) + pointMap.get(road[1]);
    //     }

    //     return totalImportance;
    // }

    public long maximumImportance(int n, int[][] roads) {
        int[] freq = new int[n];
        for (int[] road : roads) {
            ++freq[road[0]];
            ++freq[road[1]];
        }

        Arrays.sort(freq);

        long totalImportance = 0;
        for (int idx = 0; idx < n; ++idx) {
            totalImportance += freq[idx] * (idx + 1L);
        }

        return totalImportance;
    }

    /*
     * 
     * Iterate through the map and create a frequency map for each city
     * Place pairs of {city, connections} into a max heap
     * Using the heap, assign values starting from n going to 1 -- the cities with the most connections are assigned higher values -- need to map city to new n value
     *      If two cities have the same count -- how to deal?
     * Iterate through the roads array again, using the points map, add up the total importance of all road connections 
     */

     /*
      * I'm dumb, the second and more efficient solutions --
      * Use an array of size n to store the number of connections for each node instead of using a Hash Map
      * Sort the array in ascending order
      * Iterate through the frequency array and for each node, multiply the frequency count by idx + 1 and add it to the running count
      */

    public static void main(String[] args) {
        Maximum_Total_Importance_of_Roads solution = new Maximum_Total_Importance_of_Roads();

        int n1 = 5;
        int[][] roads1 = {{0,1}, {1,2}, {2,3}, {0,2}, {1,3}, {2,4}};
        long ans1 = 43;

        int n2 = 5;
        int[][] roads2 = {{0,3}, {2,4}, {1,3}};
        long ans2 = 20;
        long startTime = System.nanoTime();
        long test1 = solution.maximumImportance(n1, roads1);
        long test2 = solution.maximumImportance(n2, roads2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}