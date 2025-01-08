class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        int result = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int complement = target - arr[i];

            auto it = lower_bound(arr.begin() + i + 1, arr.end(), complement);

            if (it != arr.end() && *it == complement)
            {
                auto ub = upper_bound(it, arr.end(), complement);
                result += (ub - it);
            }
        }

        return result;
    }
};