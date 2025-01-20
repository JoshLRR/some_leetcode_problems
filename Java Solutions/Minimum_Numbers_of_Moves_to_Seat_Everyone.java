import java.util.Arrays;

class Minimum_Numbers_of_Moves_to_Seat_Everyone {

    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);

        int moves = 0;

        for (int idx = 0; idx < seats.length; ++idx) {
            moves += Math.abs(students[idx] - seats[idx]);
        }

        return moves;
    }
    public static void main(String[] args) {
        Minimum_Numbers_of_Moves_to_Seat_Everyone solution = new Minimum_Numbers_of_Moves_to_Seat_Everyone();

        int[] seats1 = {3,1,5};
        int[] students1 = {2,7,4};
        int ans1 = 4;

        int[] seats2 = {4,1,5,9};
        int[] students2 = {1,3,2,6};
        int ans2 = 7;

        int[] seats3 = {2,2,6,6};
        int[] students3 = {1,3,2,6};
        int ans3 = 4;
        long startTime = System.nanoTime();
        int test1 = solution.minMovesToSeat(seats1, students1);
        int test2 = solution.minMovesToSeat(seats2, students2);
        int test3 = solution.minMovesToSeat(seats3, students3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}