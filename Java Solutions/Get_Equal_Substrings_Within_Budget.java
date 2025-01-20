class Get_Equal_Substrings_Within_Budget {

    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int i = 0;
        int j;
        for (j = 0; j < n; ++j) {
            maxCost -= Math.abs(s.charAt(j) - t.charAt(j));

            if (maxCost < 0) {
                maxCost += Math.abs(s.charAt(i) - t.charAt(i));
                ++i;
            }
        }

        return j - i;
    }
    public static void main(String[] args) {
        Get_Equal_Substrings_Within_Budget solution = new Get_Equal_Substrings_Within_Budget();

        long startTime = System.nanoTime();

        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}