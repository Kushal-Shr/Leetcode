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
        queue<int> ansIdx;

        if (tot1 >= tot2)
        {
            int sum1 = 0, sum2 = 0;

            for (int i = 0; i < n; i++)
            {
                sum1 += gas[i]; sum2 += cost[i];

                if (sum1 >= sum2)
                    ansIdx.push(i);

                else
                {
                    while (!ansIdx.empty())
                        ansIdx.pop();

                    sum1 = 0; sum2 = 0;
                }
            }

            ans = ansIdx.front();
        }

        return ans;
    }
};