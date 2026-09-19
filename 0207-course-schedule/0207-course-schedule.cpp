class Solution {
public:
    bool dfs(int curr, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& edges)
    {
        vis[curr] = true;
        recPath[curr] = true;

        for (int i = 0; i < edges.size(); i++)
        {
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == curr)
            {
                if (!vis[v])
                {
                    if (dfs(v, vis, recPath, edges))
                        return true;
                }

                else if (recPath[v])
                    return true;
            }
        }

        recPath[curr] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for (int i = 0; i < numCourses; i++)
            if (!vis[i])
                if (dfs(i, vis, recPath, prerequisites))
                    return false;

        return true;
    }
};