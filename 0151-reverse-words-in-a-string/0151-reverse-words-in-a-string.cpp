class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        string word = "", ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                word += s[i];
            }
            else if (!word.empty())
            {
                arr.push_back(word);
                word = "";
            }
        }

        if (!word.empty())
        {
            arr.push_back(word);
        }

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            ans += arr[i];

            if (i != 0)
            {
                ans +=  " ";
            }
        }

        return ans;

    }
};