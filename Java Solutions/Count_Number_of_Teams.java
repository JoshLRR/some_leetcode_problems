class Count_Number_of_Teams {

    public int numTeams(int[] rating) {
        int teams = 0;
        int n = rating.length;

        for (int idx = 0; idx < n; ++idx) {
            int leftSmaller = 0, leftLarger = 0, rightSmaller = 0, rightLarger = 0;

            for (int jdx = 0; jdx < idx; ++jdx) {
                if (rating[jdx] < rating[idx]) ++leftSmaller;
                if (rating[jdx] >  rating[idx]) ++leftLarger; 
            }

            for (int jdx = idx + 1; jdx < n; ++jdx) {
                if (rating[jdx] > rating[idx]) ++rightLarger;
                if (rating[jdx] < rating[idx]) ++rightSmaller;
            }

            teams += leftSmaller * rightLarger + leftLarger * rightSmaller;
        }

        return teams;
    }

    public static void main(String[] args) {
        Count_Number_of_Teams solution = new Count_Number_of_Teams();
        
        int[] rating1 = {2,5,3,4,1};
        int ans1 = 3;

        int[] rating2 = {2,1,3};
        int ans2 = 0;

        int[] rating3 = {1,2,3,4};
        int ans3 = 4;
        long startTime = System.nanoTime();
        int test1 = solution.numTeams(rating1);
        int test2 = solution.numTeams(rating2);
        int test3 = solution.numTeams(rating3);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}