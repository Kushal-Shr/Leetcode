class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        sort(nums1.begin(), nums1.end());

        double ans;

        if (nums1.size() % 2 != 0)
            ans = nums1[nums1.size() / 2];

        else
            ans = (static_cast<double>(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1])) / 2;

        return ans;
    }
};