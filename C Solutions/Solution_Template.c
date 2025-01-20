#include <stdio.h>
#include <assert.h>
#include <time.h>

#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

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
