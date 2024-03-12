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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }        
        head = prev;

        return head;
    }
};

/*

*/

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

bool compareLists(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr; // Both should be nullptr if lists are equal
}

int main() {
    Solution solution;

    // Test 1: Empty list
    ListNode* test1 = nullptr;
    ListNode* result1 = solution.reverseList(test1);
    assert(compareLists(result1, nullptr));
    
    // Test 2: Single element list
    ListNode* test2 = new ListNode(1);
    ListNode* expected2 = new ListNode(1);
    ListNode* result2 = solution.reverseList(test2);
    assert(compareLists(result2, expected2));
    
    // Test 3: Multiple elements list
    ListNode* test3 = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode* expected3 = new ListNode(3, new ListNode(2, new ListNode(1)));
    ListNode* result3 = solution.reverseList(test3);
    assert(compareLists(result3, expected3));
    
    std::cout << "\033[32mAll tests passed!\033[0m\n";

    // Cleanup
    delete expected2;
    delete result2; // Assuming this points to a new list and not altering the input list
    // For test3 and expected3, you would need to delete each node in the list to prevent memory leaks.
    // In a real-world scenario, consider using smart pointers or a list destructor for better memory management.

    return 0;
}