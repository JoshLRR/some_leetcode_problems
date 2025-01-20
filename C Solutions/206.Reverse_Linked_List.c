#include <stdio.h>
#include <assert.h>
#include <time.h>

#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if (!head) return NULL;

    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;

    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

/* 
    Temp holds curr->next
    curr->next becomes prev
    curr becomes temp (curr->next);
*/

int main() {

    // Function calls go inside here
    clock_t t0 = clock(); 

    clock_t end = clock(); 

    double time = ((double)(end - t0) / CLOCKS_PER_SEC) * 1000;  // Time in ms

    // assert(test1 == ans1);
    // assert(test2 == ans2);

    printf(GREEN_TEXT "All tests passed in %.3f ms!\n" RESET_TEXT, time);

    return 0;
}
