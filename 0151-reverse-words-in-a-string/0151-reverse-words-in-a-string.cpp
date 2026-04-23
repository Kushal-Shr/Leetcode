class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        string sent = "";
        string word;

        for (int i = 0; i < s.length(); i++)
        {
            word = "";
            
            while (i < s.length() && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if (word.length() > 0)
                sent += ' ' + word;
        }

        return sent.substr(1);
    }
};