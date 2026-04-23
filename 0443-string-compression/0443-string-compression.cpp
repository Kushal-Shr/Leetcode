class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        int count;
        char ch;

        for (int i = 0; i < n;)
        {
            ch = chars[i];
            count = 0;

            while (i < n && chars[i] == ch)
            {
                count++;
                i++;
            }

            if (count == 1) chars[idx++] = ch;

            else
            {
                chars[idx] = ch;
                idx++;

                string num = to_string(count);

                for (char num_ch: num)
                {
                    chars[idx] = num_ch;
                    idx++;
                }
            }
        }

        return idx;
    }
};