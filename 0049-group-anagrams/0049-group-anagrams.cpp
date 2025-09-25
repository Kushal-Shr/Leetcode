class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> occ;
        vector<vector<string>> grps;
        for (string word: strs)
        {
            string new_word = word;
            sort(new_word.begin(), new_word.end());

            occ[new_word].push_back(word);
        }

        for (const auto& pair : occ)
        {
            grps.push_back(pair.second);
        }

        return grps;
    }
};