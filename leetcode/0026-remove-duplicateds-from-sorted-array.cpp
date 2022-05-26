// 26. Remove Duplicates from Sorted Array
// Array, Two Pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        
        int len = 1;
        int checkValue = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != checkValue)
            {
                nums[len] = nums[i];
                checkValue = nums[i];
                len++;
            }
        }
        return len;
    }
};