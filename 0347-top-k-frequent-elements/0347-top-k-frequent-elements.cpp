class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(k, 0);

        unordered_map<int, int> count;

        for (int num: nums)
        {
            if (count[num] >= 1)
            {
                count[num] += 1;
            }
            else
            {
                count[num] = 1;
            }
        }

        for (int i = 0; i < k; i++)
        {
            int max_freq = INT_MIN;
            int max_num = 0;
            for (const auto &pair: count)
            {
                if (pair.second > max_freq)
                {
                    max_num = pair.first;
                    max_freq = pair.second;
                }
            }
            freq[i] = max_num;
            count[max_num] = -1;
        }

        return freq;
    }
};