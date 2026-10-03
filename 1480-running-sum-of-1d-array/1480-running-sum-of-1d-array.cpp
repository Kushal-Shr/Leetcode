class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int left = 0;
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = nums[i] + left;
            left += nums[i];
        }

        return ans;
    }
};