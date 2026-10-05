class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        sort(jewels.begin(), jewels.end());
        sort(stones.begin(), stones.end());

        int i = 0, j = 0;

        int ans = 0;
        while (i < jewels.size() && j < stones.size())
        {
            if (jewels[i] > stones[j])
                j++;

            else if (jewels[i] == stones[j])
            {
                ans++;
                j++;
            }
            else if (jewels[i] < stones[j])
                i++;
        }

        return ans;
    }
};