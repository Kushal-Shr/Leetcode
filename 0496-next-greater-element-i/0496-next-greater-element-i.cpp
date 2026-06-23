class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);

        int i = 0;
        for (int n: nums1)
        {
            stack<int> st;

            for (int j = nums2.size() - 1; j >= 0; j--)
            {
                if (nums2[j] != n)
                    st.push(nums2[j]);

                else
                {
                    while (!st.empty())
                    {
                        if (st.top() > n)
                        {
                            ans[i] = st.top();
                            break;
                        }

                        else
                            st.pop();
                    }
                }
            }

            i++;
        }

        return ans;
    }
};