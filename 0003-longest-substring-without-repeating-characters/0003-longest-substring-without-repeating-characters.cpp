class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // a set to keep track of duplicates
        unordered_set<char> seen;

        int maxLen = 0;
        int st = 0, end = 0;

        while (end < s.length())
        {
            if (seen.find(s[end]) == seen.end())
            {
                seen.insert(s[end]);
                maxLen = max(maxLen, end - st + 1);
                end++;
            }
            else
            {
                seen.erase(s[st]);
                st++;
            }
        }

        return maxLen;
    }
};

// p w w k e w
// 0 0 1 
// 1 2 