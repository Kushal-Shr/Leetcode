class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> q;

        for (int i = 0; i < s.length(); i++) // Loop with index
        {
            char ch = s[i];
            if (m.find(ch) == m.end())
            {
                m[ch]++;
                q.push(i); // FIX 1: Push the index
            }
            else
                m[ch]++;
        }

        while (!q.empty() && m[s[q.front()]] > 1)
        {
            q.pop();
        }

        if (q.empty()) return -1;
        else return q.front();
    }
};