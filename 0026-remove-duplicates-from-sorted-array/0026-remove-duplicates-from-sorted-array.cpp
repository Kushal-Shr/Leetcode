class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;

        while (j < nums.size())
        {
            if (nums[i] == nums[j])
            {
                nums.erase(nums.begin() + j);
            }

            else
            {
                i++;
                j++;
            }
        }

        int count = 0;

        for (int i = 0; i < nums.size(); i++)
            count++;

        return count;
    }
};