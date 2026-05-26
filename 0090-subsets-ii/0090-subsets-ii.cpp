class Solution {
private:
    void subsets(vector<int> &nums, vector<vector<int>> &ans, vector<int> &subset, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(subset);
            return;     
            
        }

        subset.push_back(nums[i]);
        subsets(nums, ans, subset, i + 1);

        subset.pop_back();
        int idx = i + 1;

        while (idx < nums.size() && nums[idx] == nums[idx - 1])
            idx++;

        subsets(nums, ans, subset, idx);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;

        int i = 0;

        subsets(nums, ans, subset, i);

        return ans;
    }
};