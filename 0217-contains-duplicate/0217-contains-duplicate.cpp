class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> occ;

        for (int num: nums)
        {
            if (occ[num] == true)
                return true;

            else
                occ[num] = true;
        }

        return false;
    }
};