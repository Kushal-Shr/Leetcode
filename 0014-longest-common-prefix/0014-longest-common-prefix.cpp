class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word = "";
        bool no_match = false;

        int min_len = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i].size() < min_len)
                min_len = strs[i].size();
        }

        for (int i = 0; i < min_len; i++)
        {
            word += strs[0][i];
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] != word[word.size() - 1])
                {
                    no_match = true;
                }
            }
            if (no_match)
            {
                word.pop_back();
                break;
            }
        }
        return word;
    }
};