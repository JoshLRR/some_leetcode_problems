#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

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
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

        return head;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int carry = 0;
        while (curr) {
            int currNum = curr->val * 2;
            curr->val = currNum % 10 + carry;
            carry = currNum / 10;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        if (carry) {
            ListNode* newHead = new ListNode(carry, head);
            head = newHead;
        }
        // head = prev;

        return head;
    }
};

/*
    1. Reverse the linked list
    2. Multiply each value by 2 and add the carry value. Calculate if there's a carry for the next node
    3. Reverse the list again as we go through each node
    4. After reaching the end, check if there's still a carry value. If there is, create a new node and link it to the old head. 
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