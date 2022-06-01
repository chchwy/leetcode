// 77. Combinations
// Backtracking

#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    void backtrack(vector<int>& cb, int next, int n, int k, vector<vector<int>>& combinations) {
        
        if (cb.size() == k) {
            combinations.push_back(cb);
            return;
        }
        
        for (int i = next; i <= n; ++i) {
            cb.push_back(i);
            backtrack(cb, i + 1, n, k, combinations);
            cb.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
     
        // pick k numbers from [1, n]
        vector<vector<int>> combinations;
        
        // n = 4, k =2
        // 1, 2, 3, 4
        // 1
        // 1  2
        // 1     3
        // 1        4
        //    2  3
        //    2     4
        //       3  4
        
        for (int i = 1; i <= (n - k + 1); ++i) {
        
            vector<int> cb;
            cb.push_back(i);
            backtrack(cb, i + 1, n, k, combinations);
            cb.pop_back();
        }
        
        return combinations;
    }
};

int main() {
    Solution sln;
    auto results = sln.combine(3, 3);

    int i = 0;
    for (auto& combination : results) {
        std::cout << "[" << i++ << "]:";
        for (int n : combination) {
            std::cout << n << ", ";
        }
        std::cout << std::endl;
    }

}