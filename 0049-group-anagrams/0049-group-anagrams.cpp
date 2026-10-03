class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (string val: strs)
        {
            string new_str = val;
            sort(new_str.begin(), new_str.end());

            m[new_str].push_back(val);
        } 

        vector<vector<string>> vec;

        for (auto pair: m)
            vec.push_back(pair.second);

        return vec; 
    }
};