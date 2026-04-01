class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();

        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        for (int val: nums)
        {
            if (val == 0) zeroCount++;
            if (val == 1) oneCount++;
            if (val == 2) twoCount++;
        }

        for (int i = 0; i < size; i++)
        {
            if (zeroCount-- > 0) nums[i] = 0;
            else if (oneCount-- > 0) nums[i] = 1;
            else if (twoCount-- > 0) nums[i] = 2;
        }
    }
};