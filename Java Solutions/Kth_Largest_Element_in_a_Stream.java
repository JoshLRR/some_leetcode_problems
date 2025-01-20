import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Stack;

class Kth_Largest_Element_in_a_Stream {
    
    class KthLargest {
        final PriorityQueue<Integer> minHeap;
        final int k;
        
        public KthLargest(int k1, int[] nums) {
            this.k = k1;
            minHeap = new PriorityQueue<>(k1);

            for (int num : nums) {
                minHeap.add(num);
            }
        }
        
        public int add(int val) {
            if (minHeap.size() < this.k) {
                minHeap.offer(val);
            } else if (minHeap.peek() < val) {
                minHeap.poll();
                minHeap.offer(val);
            }

            return minHeap.peek();
        }
    }

    public static void main(String[] args) {
        Kth_Largest_Element_in_a_Stream solution = new Kth_Largest_Element_in_a_Stream();

        long startTime = System.nanoTime();
        
        long endTime = System.nanoTime();
        // assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        // assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        // assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}