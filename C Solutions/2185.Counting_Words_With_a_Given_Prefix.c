#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

int prefixCount(char** words, int wordsSize, char* pref) {
    int count = 0;
    int prefLen = strlen(pref);

    for (int idx = 0; idx < wordsSize; ++idx) {
        if (strncmp(words[idx], pref, prefLen) == 0) {
            ++count;
        }
    }

    return count;
}

int main() {
    char* words1[] = {"pay", "attention", "practice", "attend"};
    char* pref1 = "at";
    int wordsSize1 = sizeof(words1) / sizeof(words1[0]);
    int ans1 = 2;

    char* words2[] = {"leetcode","win","loops","success"};
    char* pref2 = "code";
    int wordsSize2 = sizeof(words2) / sizeof(words2[0]);
    int ans2 = 0;

    clock_t t0 = clock(); 
    int test1 = prefixCount(words1, wordsSize1, pref1);
    int test2 = prefixCount(words2, wordsSize2, pref2);
    clock_t end = clock(); 

    double time = ((double)(end - t0) / CLOCKS_PER_SEC) * 1000;  // Time in ms

    assert(test1 == ans1);
    assert(test2 == ans2);

    printf(GREEN_TEXT "All tests passed in %.6f ms!\n" RESET_TEXT, time);

    return 0;
}
