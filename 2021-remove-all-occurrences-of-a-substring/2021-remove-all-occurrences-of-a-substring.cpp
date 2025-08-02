class Solution {
public:
    string removeOccurrences(string s, string part) {
        int s_len = s.size();
        int part_len = part.size();

        int i = 0;

        while (i <= (int)s.size() - part_len)
        {
            string temp = s.substr(i, part_len);

            if (temp == part)
            {
                s.erase(i, part_len);

                i = max(0, i - part_len + 1);
            }
            else 
            {
                i++;
            }
        }

        return s;
    }
};