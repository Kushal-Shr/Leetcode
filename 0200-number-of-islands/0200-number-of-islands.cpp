class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1' || vis[r][c] == true)
            return ;

        vis[r][c] = true;

        dfs(grid, vis, r - 1, c);
        dfs(grid, vis, r + 1, c);
        dfs(grid, vis, r, c - 1);
        dfs(grid, vis, r, c + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<bool>> vis(r, vector<bool>(c, false));

        int ans = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == false)
                {
                    dfs(grid, vis, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};