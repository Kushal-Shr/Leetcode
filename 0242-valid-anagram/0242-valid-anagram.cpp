class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        if (s.size() != t.size())
            return false;

        for (char ch: s)
        {
            if (count[ch] > 0)
                count[ch] += 1;
            else
                count[ch] = 1;
        }

        for (char ch: t)
        {
            if (count.find(ch) == count.end() || count[ch] == 0)
                return false;

            else 
                count[ch] -= 1;
        }

        return true;
    }
};