#include <iostream>
#include <cassert>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* preHead = new ListNode();
        ListNode* dummy = preHead;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                dummy->next = list2;
                list2 = list2->next;
            } else {
                dummy->next = list1;
                list1 = list1->next;
            }
            dummy = dummy->next;
        }

        if (list1) {
            dummy->next = list1;
        }
        if (list2) {
            dummy->next = list2;
        }

        return preHead->next;
    }
};
/*

*/

// Test Functions
ListNode* vectorToList(const std::vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int num : v) {
        ListNode* newNode = new ListNode(num);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

std::vector<int> listToVector(ListNode* head) {
    std::vector<int> v;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }
    return v;
}

void assertListsEqual(ListNode* l1, ListNode* l2) {
    std::vector<int> v1 = listToVector(l1);
    std::vector<int> v2 = listToVector(l2);
    assert(v1 == v2);
}

// Test Cases
void runTests() {
    Solution solution;
    ListNode* result;

    // Test Case 1: Both lists are empty
    assertListsEqual(solution.mergeTwoLists(nullptr, nullptr), nullptr);

    // Test Case 2: One list is empty, and the other is not
    ListNode* list2_1 = vectorToList({1, 2, 3});
    assertListsEqual(solution.mergeTwoLists(nullptr, list2_1), list2_1);

    // Test Case 3: Both lists have the same length
    ListNode* list3_1 = vectorToList({1, 3, 5});
    ListNode* list3_2 = vectorToList({2, 4, 6});
    result = solution.mergeTwoLists(list3_1, list3_2);
    assertListsEqual(result, vectorToList({1, 2, 3, 4, 5, 6}));

    // Test Case 4: Lists have different lengths
    ListNode* list4_1 = vectorToList({1, 2});
    ListNode* list4_2 = vectorToList({3, 4, 5});
    result = solution.mergeTwoLists(list4_1, list4_2);
    assertListsEqual(result, vectorToList({1, 2, 3, 4, 5}));

    // Test Case 5: All elements in one list are smaller than those in the other
    ListNode* list5_1 = vectorToList({1, 2, 3});
    ListNode* list5_2 = vectorToList({4, 5, 6});
    result = solution.mergeTwoLists(list5_1, list5_2);
    assertListsEqual(result, vectorToList({1, 2, 3, 4, 5, 6}));

    // Test Case 6: Lists have some common elements
    ListNode* list6_1 = vectorToList({1, 3, 5});
    ListNode* list6_2 = vectorToList({1, 2, 3});
    result = solution.mergeTwoLists(list6_1, list6_2);
    assertListsEqual(result, vectorToList({1, 1, 2, 3, 3, 5}));

    std::cout << "\033[32mAll tests passed!\033[0m\n";
}


int main() {
    Solution solution;

    runTests();

    // std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}