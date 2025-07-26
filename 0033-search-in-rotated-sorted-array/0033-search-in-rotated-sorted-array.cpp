class Solution {
public:
    int findPivot(vector<int> nums)
    {
        int s = 0, e = nums.size() - 1, m;

        if (nums[s] <= nums[e])
            return 0;

        while (s < e)
        {
            m = (s + e) / 2;

            if (nums[m] >= nums[0])
            {
                s = m + 1;
            }

            else 
            {
                e = m;
            }
        }
        return s;
    
    }

    int search(vector<int>& nums, int target) 
    {
        long long int pivot = findPivot(nums);
        int s, e, m;

        if (pivot == 0 || target >= nums[0])
        {
            s = 0;
            e = (pivot == 0) ? nums.size() - 1 : pivot - 1;
        }
        else 
            s = pivot, e = nums.size() - 1;

        while (s <= e)
        {
            m = (s + e) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] > target)
            {
                e = m - 1;
            }
            else 
            {
                s = m + 1;
            }
        }
        return -1;
    }
};