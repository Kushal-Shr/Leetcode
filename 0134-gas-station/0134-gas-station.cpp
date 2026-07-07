class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot1 = 0, tot2 = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++)
        {
            tot1 += gas[i];
            tot2 += cost[i];
        }

        int ans = -1;

        if (tot1 >= tot2)
        {
            int sum1 = 0, sum2 = 0;
            int count = 0;

            for (int i = 0; i < n; i++)
            {
                sum1 += gas[i]; sum2 += cost[i];

                if (sum1 >= sum2)
                {
                    ans = i;
                    count++;
                }

                else
                {
                    sum1 = 0; sum2 = 0;
                    ans = -1;
                    count = 0;
                }
            }

            ans = ans - count + 1;
        }

        return ans;
    }
};