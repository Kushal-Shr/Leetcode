class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;

        while (i < (int)s.size() - 1)
        {
            if (s[i] == s[i + 1])
            {
                s.erase(i, 2);
                i = max(0, i - 1);
            }
            else 
            {
                i++;
            }
        }
        return s;
    }
};