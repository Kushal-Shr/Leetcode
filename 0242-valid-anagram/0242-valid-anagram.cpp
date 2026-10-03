class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;

        for (char ch: s)
            m[ch]++;

        for (char ch: t)
            m[ch]--;

        for (auto pair: m)
        {
            if (pair.second != 0)
                return false;
        }
        return true;
    }
};