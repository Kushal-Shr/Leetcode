class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int source, int destination, vector<bool> &vis)
    {
        if (source == destination)
            return true;
        
        vis[source] = true;

        for (int v: adj[source])
        {
            if (!vis[v])
                if (dfs(adj, v, destination, vis))
                    return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)
            return true;

        vector<vector<int>> adj(n);

        for (auto list: edges)
        {
            adj[list[0]].push_back(list[1]);
            adj[list[1]].push_back(list[0]);
        }

        // 0: 1 2
        // 1: 0 2
        // 2: 0 1

        vector<bool> vis(n, false);

        return dfs(adj, source, destination, vis);
    }
};