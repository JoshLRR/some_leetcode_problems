#include <iostream>
#include <cassert>

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        } 

        return false;
        
        
        // do {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // } while (slow != fast && fast != nullptr && fast->next != nullptr);

        // return (fast != nullptr && fast->next != nullptr);
    }
};

/*
    Floyd's tortoise and hare for cycle detection
    if slow == fast and fast == nullptr and fast->next == nullptr, end of the list has been reached.
        fast != nullptr && fast->next != nullptr will return false
    if slow == fast and fast !=nullptr and fast->next != nullptr, a cycle has been detected as fast has looped back around and isn't stuck at a nullptr -- returns true
*/

void deleteList(ListNode* &head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;
    ListNode* head1 = new ListNode(3);
    ListNode* node1 = new ListNode(2, new ListNode(0));
    ListNode* tail1 = new ListNode(-4, node1);
    assert(solution.hasCycle(head1));
    deleteList(head1);

    ListNode* head2 = new ListNode(1);
    ListNode* tail2 = new ListNode(2, head2);
    assert(solution.hasCycle(head2));
    deleteList(head2);

    ListNode* head3 = new ListNode(1);
    assert(!solution.hasCycle(head3));
    deleteList(head3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}