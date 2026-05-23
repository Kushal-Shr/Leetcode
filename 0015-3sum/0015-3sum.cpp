class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // set<vector<int>> triplets;
        vector<vector<int>> ans;
        vector<int> trip;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
                int j = i + 1, k = n - 1;

                while (j < k)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        trip = {nums[i], nums[j], nums[k]};
                        ans.push_back(trip);
                        k--;
                        j++;

                        while (j < k && nums[j] == nums[j - 1])
                            j++;
                    }

                    else if (nums[i] + nums[j] + nums[k] > 0)
                    {
                        k--;
                    }

                    else if (nums[i] + nums[j] + nums[k] < 0)
                    {
                        j++;
                    }
                }
        }

        // vector<vector<int>> ans(triplets.begin(), triplets.end());
        
        return ans;
    }
};