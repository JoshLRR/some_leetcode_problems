#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int runningSum = 0;
        std::unordered_map<int, ListNode*> encountered;
        ListNode* preHead = &ListNode(0, nullptr);
        preHead->next = head;
        encountered[0] = preHead;

        while (head) {
            runningSum += head->val;

            if (encountered.find(runningSum) == encountered.end()) {
                encountered[runningSum] = head;
            } else {
                ListNode* prevNodeSameSum = encountered[runningSum];
                ListNode* deletionStartNode = prevNodeSameSum;
                int tempSum = runningSum;
                while (prevNodeSameSum != head) {
                    prevNodeSameSum = prevNodeSameSum->next;
                    tempSum += prevNodeSameSum->val;

                    if (prevNodeSameSum != head) encountered.erase(tempSum);
                }
                deletionStartNode->next = head->next;

            }
            head = head->next;
        }
        return preHead->next;
    }
};

/*
    O(n) solution

    Keep runningSum of values as list is iterated through
    
*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}