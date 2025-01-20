class Find_the_Minimum_and_Maximum_Number_of_Nodes_Between_Critical_Points {
    
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public int[] nodesBetweenCriticalPoints(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return new int[]{-1, -1};  // Not enough nodes to have a critical point
        }
    
        int lastNodeValue = head.val;
        ListNode curr = head.next;
        ListNode next = curr.next;
    
        int firstCritPos = -1;
        int lastCritPos = -1;
        int pos = 1;
        int minDistance = Integer.MAX_VALUE;
        int maxDistance = Integer.MIN_VALUE;
    
        while (next != null) {
            if ((curr.val > lastNodeValue && curr.val > next.val) || (curr.val < lastNodeValue && curr.val < next.val)) {
                if (firstCritPos == -1) {
                    firstCritPos = pos;
                } else {
                    minDistance = Math.min(minDistance, pos - lastCritPos);
                }
                lastCritPos = pos;
                maxDistance = pos - firstCritPos;
            }
            lastNodeValue = curr.val;
            curr = next;
            next = next.next;
            pos++;
        }
    
        if (minDistance == Integer.MAX_VALUE) {
            return new int[]{-1, -1};  // No critical points or only one critical point found
        }
    
        return new int[]{minDistance, maxDistance};
    }

    public static void main(String[] args) {
        Find_the_Minimum_and_Maximum_Number_of_Nodes_Between_Critical_Points solution = new Find_the_Minimum_and_Maximum_Number_of_Nodes_Between_Critical_Points();

        long startTime = System.nanoTime();
        
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        assert test3 == ans3 : "Test 3 failed, got " + test3 + " instead of " + ans3;

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}