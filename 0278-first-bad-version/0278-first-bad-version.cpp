// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1, end = n;

        while (st <= end)
        {
            if (isBadVersion(st))
                return st;

            int mid = st + (end - st) / 2;

            if (isBadVersion(mid))
                end = mid - 1;
            else
                st = mid + 1;
        }

        return st;
    }
};


// 1 2 3 4 5
// f t t t t
// s e      