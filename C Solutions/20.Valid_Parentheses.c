#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

bool isValid(char* s) {
    char *q = s;

    for (char* p = s; *p; p++) {
        switch(*p) {
            case '(':
                *q++ = ')';
                continue;
            case '[':
                *q++ = ']';
                continue;
            case '{':
                *q++ = '}';
                continue;
            default:
                if (q == s || *p != *--q) {
                    return false;
                }
        }
    }
    return q == s;    
}

/*
    Doesn't run locally but is accepted by LeetCode? idk why
*/

int main() {
    char* s1 = "()";
    bool ans1 = true;

    char* s2 = "()[]{}";
    bool ans2 = true;

    char* s3 = "(]";
    bool ans3 = false;

    char* s4 = "([])";
    bool ans4 = true;

    // Function calls go inside here
    clock_t t0 = clock(); 
    bool test1 = isValid(s1);
    bool test2 = isValid(s2);
    bool test3 = isValid(s3);
    bool test4 = isValid(s4);
    clock_t end = clock(); 

    double time = ((double)(end - t0) / CLOCKS_PER_SEC) * 1000;  // Time in ms

    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);
    assert(test4 == ans4);

    printf(GREEN_TEXT "All tests passed in %.3f ms!\n" RESET_TEXT, time);

    return 0;
}
