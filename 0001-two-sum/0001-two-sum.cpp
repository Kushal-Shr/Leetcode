class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        int search;

        for (int i = 0; i < nums.size(); i++)
        {
            search = target - nums[i];

            if (m.find(search) != m.end())
            {
                ans.push_back(m[search]);
                ans.push_back(i);

                break;
            }

            m[nums[i]] = i;
        }

        return ans;
    }
};