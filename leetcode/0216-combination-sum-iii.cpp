// 216. Combination Sum III
// Backtracking

#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:

    int max(int a, int b) { return (a > b) ? a : b; }

    void backtrack(vector<int>& path, int next, int sum, int k, int n, vector<vector<int>>& combinations) {

        if (sum > n) return;

        if (path.size() == k) {

            if (sum == n) {
                combinations.push_back(path);
                return;
            }
        }

        for (int i = next; i <= 9; ++i) {

            sum += i;
            path.push_back(i);
            backtrack(path, i + 1, sum, k, n, combinations);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> combinations;

        // pick k numbers
        // the sum is n
        for (int i = 1; i <= (9 - k + 1); ++i) {

            vector<int> path;

            std::cout << i << std::endl;
            path.push_back(i);
            backtrack(path, i + 1, i, k, n, combinations);
            path.pop_back();
        }
        return combinations;
    }
};

int main() {

    Solution sln;
    auto results = sln.combinationSum3(3, 7);

    for (auto& cmb : results) {
        for (int i : cmb) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}