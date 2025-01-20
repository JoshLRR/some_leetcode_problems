import java.util.Arrays;

class Magnetic_Force_Between_Two_Balls {

    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int n = position.length;
        int left = 0;
        int right = position[n - 1];
        int requiredForce = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canPut(position, mid, m)) {
                requiredForce = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return requiredForce;
    }   

    private boolean canPut(int[] position, int max, int m) {
        int count = 1;
        int last = position[0];

        for (int idx = 1; idx < position.length; ++idx) {
            if (position[idx] - last >= max) {
                ++count;
                last = position[idx];
            } 
        }

        return count >= m;
    }


    public static void main(String[] args) {
        Magnetic_Force_Between_Two_Balls solution = new Magnetic_Force_Between_Two_Balls();

        int[] position1 = {1,2,3,4,7};
        int m1 = 3;
        int ans1 = 3;

        int[] position2 = {5,4,3,2,1,1000000000};
        int m2 = 2;
        int ans2 = 999999999;

        long startTime = System.nanoTime();
        int test1 = solution.maxDistance(position1, m1);
        int test2 = solution.maxDistance(position2, m2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}