#include <vector>
#include <iostream>
#include <cassert>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Helper function to create a list from a vector of values
ListNode* createList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Helper function to delete a list and free memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Helper function to convert list to vector for easy comparison
std::vector<int> listToVector(ListNode* node) {
    std::vector<int> result;
    while (node != nullptr) {
        result.push_back(node->val);
        node = node->next;
    }
    return result;
}

int main() {
    Solution solution;
    
    // Test Case 1
    ListNode* head1 = createList({1,2,3,4,5});
    ListNode* middle1 = solution.middleNode(head1);
    assert(listToVector(middle1) == std::vector<int>({3,4,5}));
    deleteList(head1); // Clean up

    // Test Case 2
    ListNode* head2 = createList({1,2,3,4,5,6});
    ListNode* middle2 = solution.middleNode(head2);
    assert(listToVector(middle2) == std::vector<int>({4,5,6}));
    deleteList(head2); // Clean up

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}
