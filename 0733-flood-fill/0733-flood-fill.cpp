class Solution {
public:
    void dfs (vector<vector<int>>& image, int sr, int sc, int orig, int color)
    {
        if (sr < 0 || sr > image.size() - 1 || sc < 0 || sc > image[0].size() - 1 || image[sr][sc] != orig)
            return ;

        image[sr][sc] = color;

        dfs(image, sr - 1, sc, orig, color);
        dfs(image, sr, sc + 1, orig, color);
        dfs(image, sr + 1, sc, orig, color);
        dfs(image, sr, sc - 1, orig, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origColor = image[sr][sc];

        if (origColor == color)
            return image;
        
        dfs(image, sr, sc, origColor, color);

        return image;
    }
};