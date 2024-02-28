#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>> trust) {
        if (n == 1) return 1;
        std::unordered_map<int, int> trusted;
        std::pair<int, int> judgeCandidate = {0,0};
        int m = trust.size();

        for (int i = 0; i < m; ++i) {
            if (trusted.find(trust[i][1]) != trusted.end()) {
                ++trusted[trust[i][1]];
            } else {
                trusted[trust[i][1]] = 1;
            }
        }

        for (auto& person : trusted) {
            if (person.second > judgeCandidate.second) {
                judgeCandidate.second = person.second;
                judgeCandidate.first = person.first;
            }
        }

        if (judgeCandidate.second != n - 1) {
            // std::cout << judgeCandidate.second << " people trust the judge" << "\n";
            // std::cout << "Not everyone trusts the judge\n";
            // std::cout << "-1" << "\n";
            return -1;
        }

        // Check if candidate trusts anyone else
        for (int i = 0; i < m; ++i) {
            if (trust[i][0] == judgeCandidate.first) {
                // std::cout << "-1" << "\n";
                return -1;
            } 
        }

        // std::cout << judgeCandidate.first << "\n";
        return judgeCandidate.first;
    }


    /*
    
    People are labeled from 1 to n
    trust[i] = {a, b} -- person a trusts person b

    1. Town judge trusts nobody
    2. Everbody trusts town judge (except the judge themself)
    3. Only one person satisfies both of these
    
    */
};

/*      Solution with faster run time, just use an array and check for votes with n-1
class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>> trust) {
        
        std::vector<int> trustCount(n+1,0);
        for(auto& t : trust)
        {
            trustCount[t[0]]--;
            trustCount[t[1]]++;
        }

        for (int i = 1; i <= n; i++) 
        {
            if(trustCount[i]==n-1)return i;
        }
        return -1;
    
    }
};
*/

int main() {
    Solution solution;
    assert(solution.findJudge(2, {{1,2}}) == 2);
    assert(solution.findJudge(3, {{1,3}, {2,3}}) == 3);
    assert(solution.findJudge(3, {{1,3}, {2,3}, {3,1}}) == -1);
    assert(solution.findJudge(3, {{1,2}, {2,3}}) == -1);

    std::cout << "All tests passed!";
}