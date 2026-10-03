class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a freq map
        unordered_map<int, int> freq;

        for (int ch: nums) freq[ch]++;
        
        vector<vector<int>> buckets(nums.size() + 1);
        
        for (auto pair: freq)
            buckets[pair.second].push_back(pair.first);

        vector<int> vec;

        for (int i = buckets.size() - 1; i >= 0 && vec.size() <= k; i--)
        {
            for (int num: buckets[i])
            {
                vec.push_back(num);

                if (vec.size() == k)
                    return vec;
            }
        }
        
        return vec;
    }
};