class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int> &candidates, int i, int target, vector<int> &combination, vector<vector<int>> &ans)
    {
        if (i == candidates.size() || target < 0)
        {
            return;
        }

        if (target == 0)
        {
            if (s.find(combination) == s.end())
            {
                ans.push_back(combination);
                s.insert(combination);
            }
            return;
        }

        combination.push_back(candidates[i]);
        helper(candidates, i + 1, target - candidates[i], combination, ans);
        helper(candidates, i, target - candidates[i], combination, ans);
        combination.pop_back();
        helper(candidates, i + 1, target, combination, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> ans;

        helper(candidates, 0, target, combination, ans);

        return ans;
    }
};