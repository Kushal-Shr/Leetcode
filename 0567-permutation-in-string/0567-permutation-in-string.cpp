class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        bool includes = false;

        for (int i = 0; i < s1.size(); i++)
        {
            count1[s1[i] - 'a']++;
        }

        // ---------------------------

        int s1_len = s1.size();

        for (int j = 0; j <= s2.size() - s1_len && s1.size() <= s2.size(); j++)
        {
            int count2[26] = {0};
            string new_s = s2.substr(j, s1_len);

            for (int i = 0; i < new_s.size(); i++)
            {
                count2[new_s[i] - 'a']++;
            }

            // ------------------

            int k = 0, l = 0;

            while (k < 26)
            {
                if (count1[k] != count2[l])
                {
                    includes = false;
                    break;
                }
                includes = true;
                k++, l++;
            }

            if (includes)
                return includes;
        }

        return includes;
    }
};