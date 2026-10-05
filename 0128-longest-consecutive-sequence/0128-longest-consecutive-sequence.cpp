class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int maxLen = 0;
        for (int num: s)
        {
            if (s.find(num + 1) != s.end())
                continue;

            int currLen = 1;
            int ele = num;
            while (s.find(ele - 1) != s.end())
            {
                currLen++;
                ele = ele - 1;
            }

            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};