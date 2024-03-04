#include <iostream>
#include <cassert>
 
/*
    Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

    Merge Sort
    Split list in half with tortoise and hare
    Keep splitting sublists in half until they're unsplittable (1 node)
    Sort
    Merge
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        if (a == nullptr) {
            tail->next = b;
        } 
        if (b == nullptr) {
            tail->next = a;
        }

        return dummy->next;
    }

    ListNode* getMiddle(ListNode* head) {
        if (!head) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = getMiddle(head);
        ListNode* nextToMid = mid->next;
        mid->next = nullptr;

        ListNode* a = sortList(head);
        ListNode* b = sortList(nextToMid);

        ListNode* sorted = merge(a, b);
        return sorted;
    }
};

bool isSorted(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode* current = head;
    while (current->next) {
        if (current->val > current->next->val) return false;
        current = current->next;
    }
    return true;
}

void deleteList(ListNode* &head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Test case 1: Normal case
    ListNode* head1 = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    head1 = solution.sortList(head1);
    assert(isSorted(head1));
    deleteList(head1); // Clean up

    // Test case 2: Empty list
    ListNode* head2 = nullptr;
    head2 = solution.sortList(head2);
    assert(isSorted(head2)); // Should still be true as an empty list is considered sorted

    // Test case 3: Single element list
    ListNode* head3 = new ListNode(1);
    head3 = solution.sortList(head3);
    assert(isSorted(head3));
    deleteList(head3); // Clean up

    // Test case 4: List with two elements
    ListNode* head4 = new ListNode(2, new ListNode(1));
    head4 = solution.sortList(head4);
    assert(isSorted(head4));
    deleteList(head4); // Clean up

    // Test case 5: List with elements in reverse order
    ListNode* head5 = new ListNode(5, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(1)))));
    head5 = solution.sortList(head5);
    assert(isSorted(head5));
    deleteList(head5); // Clean up

    // Test case 6: List with all elements being the same
    ListNode* head6 = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(1))));
    head6 = solution.sortList(head6);
    assert(isSorted(head6));
    deleteList(head6); // Clean up

    std::cout << "All tests passed!\n";
    return 0;
}