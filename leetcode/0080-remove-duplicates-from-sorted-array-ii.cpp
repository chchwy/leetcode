// 80. Remove Duplicates from Sorted Array II
// Array, Two Pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int len = 1;
        int elementCount = 1;
        int checkValue = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == checkValue)
            {
                elementCount++;
                if (elementCount < 3)
                {
                    nums[len] = nums[i];
                    len++;
                }
            }
            else
            {
                checkValue = nums[i];
                nums[len] = nums[i];
                len++;
                elementCount = 1;
            }
        }
        return len;
    }
};