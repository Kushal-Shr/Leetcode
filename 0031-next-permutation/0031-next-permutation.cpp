class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int start = nums.size() - 1;
        int pivot;

        int i = start;
        while (i > 0 && nums[i] <= nums[i - 1])
        {
            i--;
        }

        if (i > 0)
        {
            int j = start;

            while (nums[j] <= nums[i - 1])
            {
                j--;
            }

            swap(nums[i - 1], nums[j]);
        }

        pivot = i;

        while (pivot <= start)
        {
            swap(nums[pivot++], nums[start--]);
        }
    }
};