class Solution {

private:
    void solve(string digits, string output, int idx, vector<string> &ans, vector<string> map)
    {
        if (idx >= digits.size())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[idx] - '0';

        string val = map[number];

        for (int i = 0; i < val.size(); i++)
        {
            output.push_back(val[i]);
            solve(digits, output, idx + 1, ans, map);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.size() == 0) return ans;

        int idx = 0;
        
        string output = "";

        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, idx, ans, map);

        return ans;
    }
};