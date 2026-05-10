class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_set<int> s;
        vector<int> ans;

        int a, b, exp_sum = ((n * n) * (n * n + 1)) / 2, actual_sum = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                actual_sum += grid[i][j];
                if (s.find(grid[i][j]) != s.end())
                {
                    a = grid[i][j];
                    ans.push_back(grid[i][j]);
                }
                s.insert(grid[i][j]);
            }
        }

        b = exp_sum + a - actual_sum;
        ans.push_back(b);

        return ans;
    }
};