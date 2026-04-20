class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, e = s.length() - 1;
        bool valid = true;
            while (st <= e && valid)
            {
                while (st < e && !isalnum(s[st])) st++;
                while (st < e && !isalnum(s[e])) e--;

                if (tolower(s[st++]) != tolower(s[e--])) valid = false; 
            }

        return valid;
    }
};