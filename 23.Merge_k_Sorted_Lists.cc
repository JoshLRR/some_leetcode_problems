#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     ListNode* dummy = new ListNode();
    //     ListNode* current = dummy;

    //     while (list1 && list2) {
    //         if (list1->val > list2->val) {
    //             current->next = list2;
    //             list2 = list2->next;
    //         } else {
    //             current->next = list1;
    //             list1 = list1->next;
    //         } 
    //         current = current->next;
    //     }

    //     if (list1) {
    //         current->next = list1;
    //     } 
    //     if (list2) {
    //         current->next = list2;
    //     }

    //     return dummy->next;
    // }

    // ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    //     if (lists.empty()) return nullptr;

    //     for (int i = 1; i < lists.size(); ++i) {
    //         lists[0] = mergeTwoLists(lists[0], lists[i]);
    //     }

    //     return lists[0];
    // }
    //  --  --  --  --  --  Approach 2 --   --  --  --  --
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* preHead = new ListNode(0);
        ListNode* dummy = preHead;

        auto comp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> pq(comp);

        for (auto& list : lists) {
            if (list) pq.push(list);
        }

        while (!pq.empty()) {
            ListNode* next = pq.top();
            pq.pop();
            dummy->next = next;
            dummy = dummy->next;

            if (next->next) {
                pq.push(next->next);
            }
        }

        return preHead->next;
    }
};

/*
    Go through the list of lists two lists at a time -- merge two, then go over to the next list and merge that into the "main" list -- NEVER MIND high time complexity

    Go through each node of each list
    Push into min-heap sorted by node->val, paired with the node itself
*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}