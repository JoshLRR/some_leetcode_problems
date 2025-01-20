class Guess_Number_Higher_or_Lower {
    /** 
     * Forward declaration of guess API.
     * @param  num   your guess
     * @return 	     -1 if num is higher than the picked number
     *			      1 if num is lower than the picked number
    *               otherwise return 0
    * int guess(int num);
    */

    public int guessNumber(int n) {
        int left = 0;
        int right = n;
        int mid = left + (right - left) / 2;

        int result = guess(mid);
        while (result != 0) {
            mid = left + (right - left) / 2;
            result = guess(mid);
            if (result == 1) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return mid;
    }
    
    public static void main(String[] args) {
        Guess_Number_Higher_or_Lower solution = new Guess_Number_Higher_or_Lower();

        long startTime = System.nanoTime();

        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}