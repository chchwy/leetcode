/**
難度：簡單
給一串數字，從串列找出兩個數字，和剛好是某個特定值
ex. [1, 3, 5, 7] 目標:4, 答案 1+3
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int> ans(2);
        for (int i = 0; i < numbers.size(); ++i)
        {
            for (int j = i + 1; j < numbers.size(); ++j)
            {
                if (numbers[i] + numbers[j] == target)
                {
                    ans[0] = i + 1;
                    ans[1] = j + 1;
                    return ans;
                }
            }
        }
        return ans;
    }
};