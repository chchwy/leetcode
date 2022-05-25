// 34. Find First and Last Position of Element in Sorted Array
// Array, BinarySearch
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        
        int rangeBegin = -1;
        
        while(left <= right)
        {
            if (target == nums[mid])
            {
                if (mid == 0 || nums[mid - 1] != target)
                {
                    rangeBegin = mid;
                    break;
                }
            }
            
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        
        
        int rangeEnd = -1;
        
        left = 0;
        right = nums.size() - 1;
        mid = (left + right) / 2;
        
        while(left <= right)
        {
            if (target == nums[mid])
            {
                if (mid == (nums.size() - 1) || nums[mid + 1] != target)
                {
                    rangeEnd = mid;
                    break;
                }
            }
            
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        
        return {rangeBegin, rangeEnd};
    }
};