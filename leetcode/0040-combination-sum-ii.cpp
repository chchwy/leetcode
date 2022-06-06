// 40. Combination Sum II
// Backtracking

#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution {
public:

    void backtrack(const vector<int>& candidates,
        vector<int>& path,
        int pathSum,
        int startIndex,
        int target,
        vector<vector<int>>& combinations)
    {

        if (pathSum > target) return;
        if (pathSum == target) {
            combinations.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {

            if (i > startIndex && candidates[i] == candidates[i - 1])
                continue;

            path.push_back(candidates[i]);
            backtrack(candidates, path, pathSum + candidates[i], i + 1, target, combinations);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        std::sort(candidates.begin(), candidates.end());

        vector<vector<int>> combinations;
        vector<int> path;

        for (int i = 0; i < candidates.size(); ++i) {

            if (i > 0 && candidates[i] == candidates[i - 1])
                continue;

            path.push_back(candidates[i]);
            backtrack(candidates, path, candidates[i], i + 1, target, combinations);
            path.pop_back();
        }
        return combinations;
    }
};

int main() {
    vector<int> candidates{ 10, 1, 2, 7, 6, 1, 5 };
    Solution sln;
    auto results = sln.combinationSum2(candidates, 8);

    for (vector<int>& combi : results) {
        for (int i : combi) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}