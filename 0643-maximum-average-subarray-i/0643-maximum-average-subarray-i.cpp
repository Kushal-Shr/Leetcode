class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // we need a window of size k
        int i = 0, j = k - 1;

        double tempAdd = 0;
        for (int x = 0; x < k; x++)
            tempAdd += nums[x];
        // iterate the window until it hits the end
        double maxAvg = tempAdd / k;
        double currAvg = maxAvg;

        while (j < nums.size() - 1)
        {
            double avg = ((currAvg * k) - nums[i] + nums[j + 1]) / k;

            maxAvg = max(maxAvg, avg);
            currAvg = avg;

            i++; j++;
        }

        return maxAvg;
    }
};