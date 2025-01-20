#include <stdio.h>
#include <assert.h>
#include <time.h>

#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"


struct ListNode {
    int val;
    struct ListNode *next;
}; 

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1 && !list2) return NULL;
    if (!list1) return list2;
    if (!list2) return list1;

    struct ListNode* preHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* head = preHead;
    preHead->next = head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            head->next = list1;
            list1 = list1->next;
        } else if (list2->val < list1->val) {
            head->next = list2;
            list2 = list2->next;
        } else {
            head->next = list1;
            list1 = list1->next;
        }

        head = head->next;
    }

    if (list1) {
        head->next = list1;
    }
    if (list2) {
        head->next = list2;
    }

    return preHead->next;
}

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
