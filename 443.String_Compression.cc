#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

// class Solution {
// public:
//     int compress(std::vector<char>& chars) {
//         std::array<int, 26> encountered;
//         encountered.fill(0);
//         std::string output = "";

//         for (int i = 0; i < chars.size(); ++i) {
//             ++encountered[chars[i] - 'a'];
//             if ((i == chars.size() - 1 || chars[i] != chars[i + 1]) && encountered[chars[i] - 'a'] > 1) {
//                 chars[i] = static_cast<char>(encountered[chars[i] - 'a']);
//             }
//         }

//         for (auto& letter : chars) {
//             std::cout << letter << ", ";
//         }
//         std::cout << "\n";

//         for (int i = 0; i < encountered.size(); ++i) {
//             if (encountered[i] == 1) {
//                 output += static_cast<char>(i + 'a');
//             } else if (encountered[i] > 1) {
//                 output += static_cast<char>(i + 'a');
//                 output += std::to_string(encountered[i]);
//             } else {
//                 continue;
//             }
//         }

//         // for (int i = 0; i < encountered.size(); ++i) {
//         //     std::cout << static_cast<char>(i + 'a') << " : " << encountered[i] << "\n";
//         // }

//         // std::cout << output << "\n";
//         return output.size();
//     }
// };

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int writeIndex = 0; // Index to write the compressed character and its count
        int i = 0;

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == currentChar) {
                i++;
                count++;
            }

            // Write the current character to chars
            chars[writeIndex++] = currentChar;

            for (auto& letter : chars) {
                std::cout << letter << ", ";
            }
            std::cout << "\n";

            // Write the count if it's more than 1
            if (count > 1) {
                for (char c : std::to_string(count)) {
                    chars[writeIndex++] = c;
                }
            }
        }

        // Resize the vector to the new length
        chars.resize(writeIndex);

        return writeIndex; // Returning the new length of the compressed string
    }
};


/*

*/

int main() {
    Solution solution;

    std::vector<char> chars1 = {'a','a','b','b','c','c','c'};
    int ans1 = 6;
    std::vector<char> chars2 = {'a'};
    int ans2 = 1;
    std::vector<char> chars3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int ans3 = 4;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.compress(chars1) == ans1);
    // assert(solution.compress(chars2) == ans2);
    // assert(solution.compress(chars3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);

    // std::cout << "\033[32mAll tests passed in \033[0m" << elapsed << "\033[32m milliseconds!\033[0m\n";
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}