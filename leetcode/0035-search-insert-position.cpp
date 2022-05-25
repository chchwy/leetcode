// Classic binary search 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int upper = nums.size() - 1;
        int lower = 0;

        int m = (upper + lower) / 2;
        while(upper >= lower) {

            if (nums[m] == target) return m;
            if (nums[m] > target)
                upper = m - 1;
            else // nums[m]  < target
                lower = m + 1;

            m = (upper + lower) / 2;
        }

        // counldn't find it
        if (target > nums[m])
            return m + 1;
        else if (target < nums[m])
            return m;
    }
};