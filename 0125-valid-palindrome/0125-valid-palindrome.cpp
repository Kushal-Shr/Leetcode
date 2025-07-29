class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size();)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] - 'A' + 'a';
                i++;
            }

            else if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
                s.erase(i, 1);

            else
                i++;
        }

        int st = 0, e = s.size() - 1;

        while (st < e)
        {
            if (s[st] != s[e])
                return false;
            else 
                st++, e--;
        }

        return true;
        
    }
};