class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();

       vector<int> r(n, -1);
       vector<int> l(n, -1);
       stack<pair<int, int>> st;

       for (int i = n - 1; i >= 0; i--)
       {
        while (!st.empty() && st.top().first >= heights[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            r[i] = st.top().second;
        }

        st.push({heights[i], i});
       } 

       st = stack<pair<int, int>>();

       for (int i = 0; i < n; i++)
       {
        while (!st.empty() && st.top().first >= heights[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            l[i] = st.top().second;
        }

        st.push({heights[i], i});
       } 

       int ans = -1;

       for (int i = 0; i < n; i++)
       {
        int rightIdx = (r[i] == -1) ? n: r[i];
        int leftIdx = (l[i] == -1) ? -1: l[i];

        int currArea = heights[i] * (rightIdx - leftIdx - 1);
        ans = max(ans, currArea);
       }

       return ans;
    }
};