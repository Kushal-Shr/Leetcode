class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(),
            n2 = s2.length();

        if (n1 > n2) return false;

        bool found = false;
        int i = 0;

        vector<int> freq(26, 0);

        for (char c: s1)
            freq[c - 'a']++;

        while (i <= n2 - n1 && !found)
        {
            vector<int> win_freq(26, 0);

            for (int j = 0; j < n1; j++)
            {
                win_freq[s2[i + j] - 'a']++;
            }

            if (freq == win_freq) found = true;

            i++;
        }

        return found;
    }
};