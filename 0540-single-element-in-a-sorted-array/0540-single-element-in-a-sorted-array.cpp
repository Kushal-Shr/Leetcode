class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), st = 0, end = n - 2, ans = -1;

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) ans = nums[mid];

            if (mid % 2 == 0)
            {
                if (nums[mid - 1] == nums[mid]) end = mid - 1;
                else st = mid + 1;
            }

            else
            {
                if (nums[mid - 1] == nums[mid]) st = mid + 1;
                else end = mid - 1;
            }
        }

        return ans;
    }
};