class Solution {
private:
    void getSubsets(vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(subset);
            return ;
        }

        subset.push_back(nums[i]);
        getSubsets(nums, subset, ans, i + 1);

        subset.pop_back();
        getSubsets(nums, subset, ans, i + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset = {};
        int i = 0;

        getSubsets(nums, subset, ans, i);
        
        return ans;
    }
};