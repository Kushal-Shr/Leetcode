class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> triplets;
        vector<int> trip;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;

            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    trip = {nums[i], nums[j], nums[k]};
                    triplets.insert(trip);
                    k--;
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

        vector<vector<int>> ans(triplets.begin(), triplets.end());
        
        return ans;
    }
};