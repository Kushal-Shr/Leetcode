class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> fourNum;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int first = nums[i];

            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int second = nums[j];

                int k = j + 1, l = n - 1;

                while (k < l)
                {
                    int third = nums[k];
                    int fourth = nums[l];

                    long long sum = (long long)first + second + third + fourth;

                    if (sum == target)
                    {
                        fourNum = {first, second, third, fourth};
                        ans.push_back(fourNum);
                        k++; l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }

                    else if (sum < target)
                        k++;
                    
                    else if (sum > target)
                        l--;
                }
            }
        }

        return ans;
    }
};