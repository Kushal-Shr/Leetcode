class Solution {
public:
    void getPerms(vector<int> &nums, vector<vector<int>> &ans, vector<int> &perm, vector<bool> &used)
    {
        int n = nums.size();

        if (perm.size() == n)
        {
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (used[i]) continue;

            perm.push_back(nums[i]);
            used[i] = true;
            getPerms(nums, ans, perm, used);

            used[i] = false;
            perm.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vector<bool> used(nums.size());
        getPerms(nums, ans, perm, used);
        
        return ans;
    }
};