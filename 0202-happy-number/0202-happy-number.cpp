class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> seen;

        while (n != 1 && seen[n] != 1)
        {
            seen[n] = 1;
            int sum = 0;

            while (n > 0)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }

        return n == 1;
    }
};