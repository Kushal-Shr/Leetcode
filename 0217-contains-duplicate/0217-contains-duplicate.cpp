class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int ch: nums)
        {
            if (s.find(ch) != s.end())
                return true;

            else
                s.insert(ch);
        }

        return false;
    }
};