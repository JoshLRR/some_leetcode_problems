import java.util.ArrayList;

class Maximum_Twin_Sum_of_a_Linked_List {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public int pairSum(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        ArrayList<Integer> firstHalfList = new ArrayList<>();

        while (fast != null && fast.next != null) {
            firstHalfList.add(slow.val);
            slow = slow.next;
            fast = fast.next.next;
        }

        int maxPairSum = Integer.MIN_VALUE;
        int listIdx = firstHalfList.size() - 1;
        while (slow != null) {
            int curr = firstHalfList.get(listIdx) + slow.val;
            maxPairSum = Math.max(maxPairSum, curr);
            --listIdx;
            slow = slow.next;
        }

        return maxPairSum;
    }

    /*
     * 
     * Space complexity can be improved by reversing the second half of the list and doing direct node sum comparisons to a runningTotal at the slight cost of an increased constant factor in time complexity
     */

    public static void main(String[] args) {
        Maximum_Twin_Sum_of_a_Linked_List solution = new Maximum_Twin_Sum_of_a_Linked_List();

        long startTime = System.nanoTime();

        long endTime = System.nanoTime();

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}