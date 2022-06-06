// 39. Combination Sum
// Backtracking

#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:

    void backtrack(vector<int>& candidates,
        vector<int>& path,
        int pathSum,
        int startIndex,
        int target,
        vector<vector<int>>& combinations) {

        if (pathSum > target) return;
        if (pathSum == target) {
            combinations.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            backtrack(candidates, path, pathSum + candidates[i], i, target, combinations);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> combinations;

        vector<int> path;
        for (int i = 0; i < candidates.size(); ++i) {

            int pathSum = candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, path, pathSum, i, target, combinations);
            path.pop_back();
        }

        return combinations;
    }
};

int main() {
    Solution sln;

    vector<int> candidates{ 2, 3, 6, 7 };
    auto results = sln.combinationSum(candidates, 7);
    
    for (const auto& combination : results) {
        for (int i : combination) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}