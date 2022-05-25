#include <vector>
#include <cstdio>

using std::vector;

/**
 704. Binary Search
*/
class Solution
{
public:
    
    int binary_search(const vector<int>& nums, int target, int left, int right)
    {   
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        
        if (left == right)
            return -1;
        
        if (target < nums[mid])
        {
            return binary_search(nums, target, left, mid);
        }
        return binary_search(nums, target, mid + 1, right);
    }
    
    int search(vector<int>& nums, int target)
	{
        // [1, 2, 3, 4]
        // target is -3
        return binary_search(nums, target, 0, nums.size() - 1);
    }
};

int main()
{
	vector<int> input {-1, 0, 3, 5, 9, 12};
    Solution sln;
	printf("%d\n", sln.search(input, 9));
	return 0;
}