class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pSum(nums.size(), 0);
        int n = nums.size();

        int s = 0;
        for (int i = 0; i < n; i++)
        {
            pSum[i] += s + nums[i];
            s += nums[i];
        }

        unordered_map<int, int> m;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (pSum[i] == k)
                count++;

            if (m[pSum[i] - k] > 0)
                count += m[pSum[i] - k];

            m[pSum[i]]++;
        }

        return count;
    }
};