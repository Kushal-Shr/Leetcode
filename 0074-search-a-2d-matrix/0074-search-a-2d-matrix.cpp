class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0, end = matrix.size() - 1;
    int mid;

    int mid_st = 0, mid_end = matrix[0].size() - 1;
    int mid_m;

    bool found = false;

    while (st <= end)
    {
        mid = st + (end - st) / 2;

        if (target < matrix[mid][mid_st])
            end = mid - 1;

        else if (target > matrix[mid][mid_end])
            st = mid + 1;

        else
            break;
    }

    while (mid_st <= mid_end)
    {
        mid_m = mid_st + (mid_end - mid_st) / 2;

        if (matrix[mid][mid_m] < target)
            mid_st = mid_m + 1;

        else if (matrix[mid][mid_m] > target)
            mid_end = mid_m - 1;

        else
        {
            found = true;
            break;
        }
    }

    return found;
    }
};