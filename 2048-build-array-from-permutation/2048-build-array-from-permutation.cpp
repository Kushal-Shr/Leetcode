class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> newArr(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            newArr[i] = nums[nums[i]];
        }

        return newArr;
    }
};