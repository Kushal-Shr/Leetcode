class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0;
        int sumCount = 0;
        int n = nums.size();

        while (i < n)
        {
            int sum = 0;

            int j = i;

            while (j < n)
            {
                sum += nums[j];

                if (sum == k)
                {
                    sumCount++;
                }

                j++;
            }

            i++;
        }

        return sumCount;
    }
};