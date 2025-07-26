class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;

        int maxi = 0;

        while (s < e)
        {
            int currArea = min(height[s], height[e]) * (e - s);
            maxi = max(currArea, maxi);

            if (height[s] > height[e])
                e--;
            else
                s++;
        }

        return maxi;
    }
};