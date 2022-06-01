// 53. Maximum Subarray
// Dynamic Programming

#include <iostream>
#include <vector>
using std::vector;

int max(int a, int b) { return (a > b) ? a : b; }

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         
        vector<int> sums;
        sums.resize(nums.size());
        
        // recurrence equation
        // sums[n] means the sum of max subarray in nums[0-n] 
        // sums[n] = max(sums[n - 1] + nums[n], nums[n])
        
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sums[i] = max(sums[i - 1] + nums[i], nums[i]);
        }
        
        int maxSum = INT_MIN;
        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] > maxSum)
                maxSum = sums[i];
        }
        return maxSum;
    }
};

int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution sln;
    std::cout << sln.maxSubArray(nums);

    return 0;
}