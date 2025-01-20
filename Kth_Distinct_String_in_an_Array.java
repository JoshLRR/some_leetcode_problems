import java.util.HashMap;

class Kth_Distinct_String_in_an_Array {
    
    public String kthDistinct(String[] arr, int k) {
        int countedDistinct = 0;
        HashMap<String, Integer> encountered = new HashMap<>();
        
        for (String str : arr) {
            encountered.put(str, encountered.getOrDefault(str, 0) + 1);
        }

        for (String str : arr) {
            if (encountered.get(str) == 1) {
                ++countedDistinct;

                if (countedDistinct == k) return str;
            }
        }

        return "";
    }    

    public static void main(String[] args) {
        Kth_Distinct_String_in_an_Array solution = new Kth_Distinct_String_in_an_Array();
        String[] arr1 = {"d","b","c","b","c","a"};
        int k1 = 2;
        String ans1 = "a";

        String[] arr2 = {"aaa", "aa", "a"};
        int k2 = 1;
        String ans2 = "aaa";

        String[] arr3 = {"a", "b", "a"};
        int k3 = 3;
        String ans3 = "";

        long startTime = System.nanoTime();
        String test1 = solution.kthDistinct(arr1, k1);
        String test2 = solution.kthDistinct(arr2, k2);
        String test3 = solution.kthDistinct(arr3, k3);
        long endTime = System.nanoTime();

        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}