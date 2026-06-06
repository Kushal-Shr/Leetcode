class Solution {
public:
    bool isPal(string s)
    {
        int st = 0, e = s.length() - 1;

        while (st < e)
        {
            if (s[st] != s[e])
                return false;
            else
                st++; e--;
        }

        return true;
    }

    void getAllParts(string s, vector<string> &parts, vector<vector<string>> &ans)
    {
        if (s.length() == 0)
        {
            ans.push_back(parts);
            return;
        }

        for (int i = 0; i < s.length(); i++)
        {
            string part = s.substr(0, i + 1);

            if (isPal(part))
            {
                parts.push_back(part);
                getAllParts(s.substr(i + 1), parts, ans);
                parts.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> parts;
        vector<vector<string>> ans;

        getAllParts(s, parts, ans);

        return ans;
    }
};