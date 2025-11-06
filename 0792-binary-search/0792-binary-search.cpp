class Solution {
private:
    int helper(vector<int> &nums, int start, int end, int target)
    {
        int mid = (start + end) / 2;

        if (start > end) return -1;
        
        if (nums[mid] == target) return mid;

        else if (nums[mid] > target) return helper(nums, start, mid - 1, target);
        else return helper(nums, mid + 1, end, target);
    }
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        return helper(nums, start, end, target);
    }
};