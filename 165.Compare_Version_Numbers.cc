#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

// class Solution {
// public:
//     int compareVersion(std::string version1, std::string version2) {
//         int num1 = 0;
//         int num2 = 0;
//         int version2idx = 0;

//         for (int ptr1 = 0; ptr1 < version1.size(); ++ptr1) {
//             if (version1[ptr1] != '.') {
//                 // Add to num1
//                 if (num1 == 0) {
//                     num1 = version1[ptr1] - '0';
//                     continue;
//                 } else {
//                     // num1 += (version1[ptr1] - '0') * 10;
//                     num1 = num1 * 10 + (version1[ptr1] - '0');
//                     std::cout << num1 << "\n";
//                 }
//             } else {
//                 for (int ptr2 = version2idx; ptr2 < version2.size(); ++ptr2) {
//                     if (version2[ptr2] != '.') {
//                         // Add to num2
//                         if (num2 == 0) {
//                             num2 = version2[ptr2] - '0';
//                             continue;
//                         } else {
//                             // num2 += (version2[ptr2] - '0') * 10;
//                             num2 = num2 * 10 + (version2[ptr2] - '0');
//                         }
//                     } else {
//                         // Num is completed
//                         break;
//                     }
//                     version2idx = ptr2;
//                 }
//                 // Compare num1 and num2 -- if equal keep going. Otherwise immediately return
//                 if (num1 < num2) {
//                     std::cout << "Returning -1 : " << num1 << ", " << num2 << "\n";
//                     return -1;
//                 } else if (num1 > num2) {
//                     std::cout << "Returning 1 : " << num1 << ", " << num2 << "\n";
//                     return 1;
//                 }
//                 std::cout << "Found a . , nums1 and nums2 are: " << num1 << " : " << num2 << "\n";
//                 num1 = 0;
//                 num2 = 0;
//             }
//         }        

//         return 0;
//     }
// };

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        int idx1 = 0, idx2 = 0;
        int n1 = version1.size(), n2 = version2.size();
        int num1 = 0, num2 = 0;

        while (idx1 < n1 || idx2 < n2) {
            num1 = 0;
            num2 = 0;

            while (idx1 < n1 && version1[idx1] != '.') {
                num1 = num1 * 10 + (version1[idx1] - '0');
                ++idx1;
            }

            while (idx2 < n2 && version2[idx2] != '.') {
                num2 = num2 * 10 + (version2[idx2] - '0');
                ++idx2;
            }

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            ++idx1;
            ++idx2;
        }

        return 0;
    }
};

/*

*/

int main() {
    Solution solution;
    std::string version1 = "1.01";
    std::string version2 = "1.001";
    int ans1 = 0;
    std::string version3 = "1.0";
    std::string version4 = "1.0.0";
    int ans2 = 0;
    std::string version5 = "0.1";
    std::string version6 = "1.1";
    int ans3 = -1;
    std::string version7 = "1.0.1";
    std::string version8 = "1";
    int ans4 = 1;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.compareVersion(version1, version2) == ans1);
    assert(solution.compareVersion(version3, version4) == ans2);
    assert(solution.compareVersion(version5, version6) == ans3);
    assert(solution.compareVersion(version7, version8) == ans4);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}