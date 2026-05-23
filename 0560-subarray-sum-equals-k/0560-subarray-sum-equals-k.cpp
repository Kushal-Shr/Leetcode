class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pSum(n, 0);
        int count = 0;

        pSum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pSum[i] = pSum[i - 1] + nums[i];
        }

        unordered_map<int, int> psFreq;

        for (int j = 0; j < n; j++)
        {
            if (k == pSum[j]) count++;

            if (psFreq[pSum[j] - k] > 0)
            {
                count += psFreq[pSum[j] - k];
            }

            psFreq[pSum[j]]++;
        }

        return count;
    }
};