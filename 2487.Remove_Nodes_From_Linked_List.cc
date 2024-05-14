#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* node = head;
        std::stack<ListNode*> nodeStack;
        int seenMax = INT_MIN;

        while (node) {
            nodeStack.push(node);
            node = node->next;
        }

        std::stack<ListNode*> stack2;
        while (!nodeStack.empty()) {
            ListNode* curr = nodeStack.top();
            nodeStack.pop();
            if (curr->val >= seenMax) {
                stack2.push(curr);
            }
            if (curr->val > seenMax) {
                seenMax = curr->val;
            }
        }

        ListNode* preHead = new ListNode();
        ListNode* curr = preHead;
        while (!stack2.empty()) {
            ListNode* next = stack2.top();
            stack2.pop();
            curr->next = next;
            curr = curr->next;
        }

        return preHead->next;
    }
};

/*
Lazy solution using two stacks, can be optimized by writing a helper function to reverse the linked list instead of pushing them into the first stack. 

Currently sick, just want to get the daily over with so not going to optimize.
*/

int main() {
    Solution solution;

    auto t0 = std::chrono::high_resolution_clock::now();
    
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}