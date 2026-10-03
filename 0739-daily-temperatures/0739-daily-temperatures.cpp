class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);

        stack<int> indices;

        for (int i = 0; i < n; i++)
        {
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()])
            {
                int prev = indices.top();
                ans[prev] = i - prev;
                indices.pop();
            }

            indices.push(i);
        }

        return ans;
    }
};