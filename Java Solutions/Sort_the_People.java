import java.util.Arrays;
import java.util.Comparator;

class Sort_the_People {
    
    public String[] sortPeople(String[] names, int[] heights) {
        int n = heights.length; 
        int[][] heightsAndIndex = new int[n][2];

        for (int idx = 0; idx < n; ++idx) {
            heightsAndIndex[idx][0] = heights[idx];
            heightsAndIndex[idx][1] = idx;
        }

        Arrays.sort(heightsAndIndex, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(b[0], a[0]);
            }
        });

        String[] ans = new String[n];
        int idx = 0;
        for (int[] pair : heightsAndIndex) {
            ans[idx++] = names[pair[1]];
        }

        return ans;
    }

    public static void main(String[] args) {
        Sort_the_People solution = new Sort_the_People();

        String[] names1 = {"Mary", "John", "Emma"};
        int[] heights1 = {180, 165, 170};
        String[] ans1 = {"Mary", "Emma", "John"};

        String[] names2 = {"Alice", "Bob", "Bob"};
        int[] heights2 = {155, 185, 150};
        String[] ans2 = {"Bob", "Alice", "Bob"};

        long startTime = System.nanoTime();
        String[] test1 = solution.sortPeople(names1, heights1);
        String[] test2 = solution.sortPeople(names2, heights2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}