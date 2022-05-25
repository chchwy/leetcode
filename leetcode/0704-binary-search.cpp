#include <vector>
#include <cstdio>

using std::vector;

/**
 704. Binary Search
*/
class Solution1 // Recursive binary search
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

// While-loop Binary Search
class Solution2
{
public:
    int binary_search(const vector<int>& nums, int target, int left, int right)
    {
        int mid = (left + right) / 2;
        while (left <= right)
        {
            if (target == nums[mid])
            {
                return mid;
            }
            if (target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target)
    {
        return binary_search(nums, target, 0, nums.size() - 1);
    }
};

int main()
{
	vector<int> input {-1, 0, 3, 5, 9, 12};
    Solution1 sln;
	printf("%d\n", sln.search(input, 9));
    printf("%d\n", sln.search(input, 2));
	return 0;
}