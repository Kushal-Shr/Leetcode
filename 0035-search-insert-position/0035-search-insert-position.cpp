class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;

        int m;
        int ans = nums.size();

        while (s <= e)
        {
            m = (s + e) / 2;

            if (nums[m] == target)
            {
                return m;
            }

            else if (nums[m] > target)
            {
                ans = m;
                e = m - 1;
            }

            else 
            {
                s = m + 1;
            }
        }

        return ans;
    }
};