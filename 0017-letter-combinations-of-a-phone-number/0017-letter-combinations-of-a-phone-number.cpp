class Solution {
private:
    void solve(string digits, string output, int idx, vector<string>& ans, vector<string> letters)
    {
        if (idx >= digits.size())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[idx] - '0';
        string val = letters[number - 2];

        for (int i = 0; i < val.size(); i++)
        {
            output.push_back(val[i]);
            solve(digits, output, idx + 1, ans, letters);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string output;
        int idx = 0;

        if (digits.size() <= 0)
        {
            return ans;
        }

        solve(digits, output, idx, ans, letters);

        return ans;
    }
};