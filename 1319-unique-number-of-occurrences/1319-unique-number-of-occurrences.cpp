class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> occ_arr;

        sort(arr.begin(), arr.end());

        int i = 0;

        while (i < arr.size())
        {
            int count = 0;
            for (int j = i; j < arr.size(); j++)
            {
                if (arr[i] == arr[j]) count++;
            }

            occ_arr.push_back(count);
            i += count;
        }

        sort(occ_arr.begin(), occ_arr.end());

        for (int i = 0; i < occ_arr.size() - 1; i++)
        {
            if (occ_arr[i] == occ_arr[i + 1])
                return false;
        }

        return true;
    }
};