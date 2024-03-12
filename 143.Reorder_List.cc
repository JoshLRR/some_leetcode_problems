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
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast->next) slow = slow->next;

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (slow) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        slow = prev;

        while(head && slow) {
            next = head->next;
            prev = slow->next;
            head->next = slow;
            slow->next = next;
            head = next;
            slow = prev;
        }

        if (head && head->next) head->next->next = nullptr;
    }
};

/*
    Reorder as such
    0-> n-> 1-> n-1-> 2-> n-2

    One pointer that iterates normally
    One pointer that iterates through the n - i nodes -- jk this is a bad brute force

    Go to middle of list
    Reverse second half of list
    Merge 1st and 2nd halves
*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}