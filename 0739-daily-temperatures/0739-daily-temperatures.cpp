class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> warmer(n, 0);

        stack<int> indeces;

        for (int i = 0; i < n; i++)
        {
            while (!indeces.empty() && temperatures[indeces.top()] < temperatures[i])
            {
                int prev = indeces.top();
                indeces.pop();
                warmer[prev] = i - prev;
            }
            indeces.push(i);
        }

        return warmer;
    }
};