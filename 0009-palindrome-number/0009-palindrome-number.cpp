class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int rev = 0;
        int cpy = x;
        while (cpy > 0)
        {
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
                return 0;
            rev = (rev * 10) + (cpy % 10);
            cpy /= 10;
        }

        if (rev == x) return true;
        else return false;
    }
};