class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0)
        {
            int d = x % 10;

            if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
            return 0;

            ans = (ans * 10) + d;

            x = x / 10;
        }
        
        return ans;
    }
};