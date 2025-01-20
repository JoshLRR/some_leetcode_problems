#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

bool canConstruct(char* s, int k) {
    int sSize = strlen(s);
    // printf("sSize is %d\n", sSize);
    if (sSize < k) {
        return false;
    }

    int freqMap[26];

    for (int idx = 0; idx < 26; ++idx) {
        freqMap[idx] = 0;
    }

    for (int idx = 0; idx < sSize; ++idx) {
        // printf("%d\n", s[idx] - 'a');
        ++freqMap[s[idx] - 'a'];
    }

    int oddCount = 0;
    int evenCount = 0;

    for (int idx = 0; idx < 26; ++idx) {
        if (freqMap[idx] % 2 == 1) {
            ++oddCount;
        } 

        if (freqMap[idx] != 0 && freqMap[idx] % 2 == 0) {
            ++evenCount;
        }
    }

    if (oddCount > k) {
        return false;
    } else {
        return true;
    }
}

int main() {
    char* s1 = "annabelle";
    int k1 = 2;
    bool ans1 = true;

    char* s2 = "leetcode";
    int k2 = 3;
    bool ans2 = false;

    char* s3 = "true";
    int k3 = 4;
    bool ans3 = true;

    // Function calls go inside here
    clock_t t0 = clock(); 
    bool test1 = canConstruct(s1, k1);
    bool test2 = canConstruct(s2, k2);
    bool test3 = canConstruct(s3, k3);
    clock_t end = clock(); 

    double time = ((double)(end - t0) / CLOCKS_PER_SEC) * 1000;  // Time in ms

    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);


    printf(GREEN_TEXT "All tests passed in %.3f ms!\n" RESET_TEXT, time);

    return 0;
}
