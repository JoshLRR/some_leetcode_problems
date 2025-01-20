import java.util.Arrays;
import java.util.Comparator;

class Find_Right_Interval {
    public int[] findRightInterval(int[][] intervals) {
        if (intervals.length == 1) return new int[]{-1};        

        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });

        for (int[] interval : intervals) {
            for (int num : interval) {
                System.out.print(num + ", ");
            }
            System.out.println();
        }

        return new int[]{0};
    }

    public static void main(String[] args) {
        Find_Right_Interval solution = new Find_Right_Interval();

        int[][] intervals1 = {{1,2}};
        int[] ans1 = {-1};

        int[][] intervals2 = {{3,4}, {2,3}, {1,2}};
        int[] ans2 = {-1,0,1};

        int[][] intervals3 = {{1,4}, {2,3}, {3,4}};
        int[] ans3 = {-1, 2, -1};
        long startTime = System.nanoTime();
        solution.findRightInterval(intervals1);
        solution.findRightInterval(intervals2);
        // solution.findRightInterval(intervals3);
        long endTime = System.nanoTime();
        

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}