#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> nums3(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            nums3[i] = nums1[i] - nums2[i];
        }

        oset st;
        long long ans = 0;

        for (int i = 0; i < nums3.size(); i++)
        {
            ans += st.order_of_key({nums3[i] + diff, i});
            st.insert({nums3[i], i});
        }

        return ans;
    }
};