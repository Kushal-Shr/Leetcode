class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1,
            sum = 0;
        
        int d;
        
        while (n > 0)
        {
            d = n % 10;

            prod *= d;
            sum += d;

            n /= 10;
        }

        return (prod - sum);
    }
};