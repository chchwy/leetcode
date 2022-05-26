// 27. Remove Element
// Array, Two Pointers


// First solutsion: move the unwanted element to the end of the array
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        
        for (int i = 0; i < len; ++i) {
            if (nums[i] == val) {
                nums[i] = nums[len - 1];
                --i;
                --len;
            }
        }
        return len;
    }
};

// Second solution: using two pointers to skip the unwanted elements
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
    
        int len = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                nums[len] = nums[i];
                len++;
            }
        }
        
        return len;
    }
};

