class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> occ;

        for (int i = 0; i < numbers.size(); i++)
        {
            int sub = target - numbers[i];

            if (occ.count(sub))
            {
                return {occ[sub] + 1, i + 1};
            }
            else
                occ[numbers[i]] = i;
        }

        return {};
    }
};