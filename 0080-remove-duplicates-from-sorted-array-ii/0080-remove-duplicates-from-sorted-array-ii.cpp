class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        if (k <= 2) return k;

        for (int i = 0; i < nums.size() - 2;)
        {
            if (nums[i] == nums[i + 2])
            {
                nums.erase(nums.begin() + i + 2);
                k--;
            }
            else 
            {
                i++;
            }
        }

        return k;
    }
};