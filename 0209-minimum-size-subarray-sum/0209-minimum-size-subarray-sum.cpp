class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int sum = 0;

        while (j < nums.size())
        {
            sum += nums[j];

            while (sum >= target)
            {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        if (minLen == INT_MAX)
            minLen = 0;

        return minLen;
    }
};