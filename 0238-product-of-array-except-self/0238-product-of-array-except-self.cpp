class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> rightSum(nums.size(), 1);
        vector<int> leftSum(nums.size(), 1);
        
        for (int i = 1; i < nums.size(); i++)
            leftSum[i] *= nums[i - 1] * leftSum[i - 1];

        // [1 1 2 6]
        // [24 12 4 1]
        // [24 12 8 6]

        for (int i = nums.size() - 2; i >= 0; i--)
            rightSum[i] *= nums[i + 1] * rightSum[i + 1];

        vector<int> vec(nums.size());
        for (int i = 0; i < nums.size(); i++)
            vec[i] = rightSum[i] * leftSum[i];

        return vec;
    }
};