#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        std::unordered_set<int> newNums(nums.begin(), nums.end());

        ListNode* preHead = new ListNode();
        preHead->next = head;
        ListNode* prev = preHead;

        while (head) {
            if (newNums.find(head->val) != newNums.end()) {
                prev->next = head->next;
            } else {
                prev = head;
            }
            head = head->next;
        }

        return preHead->next;
    }
};

/*

*/

int main() {
    Solution solution;

    auto t0 = std::chrono::high_resolution_clock::now();
    
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}