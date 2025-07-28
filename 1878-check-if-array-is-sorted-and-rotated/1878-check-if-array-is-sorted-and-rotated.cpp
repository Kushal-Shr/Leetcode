class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        bool isRS = false;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] < nums[i])
                count++;
        }

        if (count <= 1)
        {
            if (count == 1 && nums[0] < nums[nums.size() - 1])
                isRS = false;

            else
                isRS = true;
        }
        
        return isRS;
    }
};