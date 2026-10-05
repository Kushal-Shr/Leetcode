class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> trip;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        // 0 0 0 0 0 1 1 2

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                if (j > i + 2 && nums[j] == nums[j - 1])
                {
                    j++;
                    continue;
                }
                if (k < n - 1 && nums[k] == nums[k + 1])
                {
                    k--;
                    continue;
                }

                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    trip.push_back(nums[i]);
                    trip.push_back(nums[j]);
                    trip.push_back(nums[k]);

                    ans.push_back(trip);
                    trip.clear();

                    k--;
                    j++;
                }

                else if (nums[i] + nums[j] + nums[k] > 0)
                    k--;

                else
                    j++;
            }
        }

        return ans;
    }
};