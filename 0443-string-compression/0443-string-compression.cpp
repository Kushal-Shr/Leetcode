class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        char ch = chars[0];
        int ans_idx = 0;

        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == ch)
            {
                count++;
            }
            else 
            {
                chars[ans_idx++] = chars[i - 1];
                ch = chars[i];
                if (count > 1)
                {
                    string cnt = to_string(count);
                    for (char cnt_s: cnt)
                    {
                        chars[ans_idx++] = cnt_s;
                    }
                }
                count = 1;
            }
        }
        chars[ans_idx++] = ch;
        if (count > 1)
        {
            string cnt = to_string(count);
            for (char cnt_s : cnt)
                chars[ans_idx++] = cnt_s;
        }
        return ans_idx;
    }
};