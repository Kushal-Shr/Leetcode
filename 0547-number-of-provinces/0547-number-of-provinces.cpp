#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int i, int n) {
        // Mark the current city as visited
        vis[i] = true;

        // Look at every other city 'j' to see if it's connected to city 'i'
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && !vis[j]) {
                // If connected and not visited, jump to city 'j' and explore its connections
                dfs(isConnected, vis, j, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // 1D visited array to track which cities we have checked
        vector<bool> vis(n, false);
        int ans = 0;

        // Iterate through all cities
        for (int i = 0; i < n; i++) {
            // If the city hasn't been visited, we've found a new province
            if (!vis[i]) {
                ans++;
                // DFS will find and mark all other cities connected to this one
                dfs(isConnected, vis, i, n);
            }
        }

        return ans;
    }
};