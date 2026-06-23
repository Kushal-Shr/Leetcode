class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> st;

        for (int j = nums2.size() - 1; j >= 0; j--)
        {
            while (!st.empty())
            {
                if (st.top() > nums2[j])
                {
                    m[nums2[j]] = st.top();
                    break;
                }
                else
                    st.pop();
            }

            if (st.empty())
                m[nums2[j]] = -1;


            st.push(nums2[j]);
        }

        // vector<int> ans(nums1.size());

        for (int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = m[nums1[i]];
        }

        return nums1;
    }
};