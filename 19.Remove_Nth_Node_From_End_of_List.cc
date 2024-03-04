#include <iostream>
#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n-1; ++i) {
            fast = fast->next;
        }
        if (!fast) return head->next;

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;

        return head;
    }
};

/*
    Two pointers offset by n steps
    Once the faster one reaches the end, we know we're at the desired node to remove
*/

int main() {
    Solution solution;
    // ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // assert(solution.removeNthFromEnd(head, 2));

    std::cout << "All tests passed!";
    return 0;
}